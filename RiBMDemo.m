%--------------------------------------------------------------------------
% Elliot Briggs
% Texas Tech University 
% Feb. 2012
%
% Update by:
% Changsong Li
% June. 2020
%
% Implementation of a Reed-Solomon decoder using RiBM, Chien search, 
% and modified Forney's algorithm.
%
% RiBM algorithm: (Reformulated inversionless Berlekamp-Massey)
% see "High-Speed Architectures for Reed Solomon Decoders" by Dilip V.
% Sarwate, and Naresh R. Shanbhag, IEEE Transactions on Very Large Scale
% Integration (VLSI) Systems, Vol. 9, Iss. 5, pp. 641-655, Aug. 2002
%--------------------------------------------------------------------------
close all; clear all;
%parameters
n = 48;%24;
k = 16;%8;
m = 8;
b = 0; %m0

nn = 2^m-1;%2^floor(log2(n)+1)-1;
kk = k+(nn-n);

%message = 1:9;         % message
%message = [20,4,5,17,22,1,2,28,3,17,6,7,10,31,11,20,4,5,1];  % message (all zeros is a codeword by definition)
%message = [3,14,62];
message = [255,254,127,73,39,38,30,2,255,254,127,73,39,38,30,2];
loc = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16];          % error locations
err = [255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255];         % error values
%RS parameters
pp = primpoly(m);
[g,t] = rsgenpoly(nn,kk,pp,b);
%[g,t] = rsgenpoly(63,61,pp,1);
%pp = primpoly(6);
%m = log2(n+1);
alpha = gf(2, m);
%generate codeword
msg = gf(message, m, pp);
code = rsenc(msg, n, k, g);
%inject errors
reccode = code;
reccode(loc) = err;
%creating alpha array
alpha_tb=gf(zeros(1, 2*t), m);
for i=1:2*t
    alpha_tb(i)=alpha^(2*t-i+b);
end
%--------------------------------------------------------------------------
%syndrome generation
%--------------------------------------------------------------------------
syndrome = gf(zeros(1, 2*t), m, pp);
for i = 1:n
    syndrome = syndrome.*alpha_tb +reccode(i);
end
syndrome = double(syndrome.x);
syndrome = fliplr(syndrome);
syndrome = gf(syndrome,m,pp);
%--------------------------------------------------------------------------
% RiBM algorithm (Reformulated inversionless Berlekamp-Massey)
% This implements the key equation solver portion of the decoder. 
% see "High-Speed Architectures for Reedäº¡olomon Decoders" by Dilip V.
% Sarwate, and Naresh R. Shanbhag
%--------------------------------------------------------------------------
k = 0;
gamma = 1;
delta = gf(zeros(1, 3*t+2), m);         
delta(3*t+1) = 1;
delta(1:(2*t)) = syndrome;
theta = delta(1:3*t+1);   
delta_next = delta;
for r=1:2*t+1
    delta = delta_next;    
    %step1
    delta_next(1:3*t+1) = (gamma*delta(2:3*t+2))-(delta(1)*theta(1:3*t+1));
    %step2
    if((delta(1) ~= 0) && (k>=0))
        theta(1:3*t+1) = delta(2:3*t+2);
        gamma = delta(1);
        k = -k-1;
    else
        %theta = theta;
        %gamma = gamma;
        k = k+1;
    end
end
lamda = delta(t+1:2*t+1);
omega = delta(1:t);
%--------------------------------------------------------------------------
% chein search: 
% find the error locations by finding the roots of lamda
%--------------------------------------------------------------------------
% inverse table
inverse_tb = gf(zeros(1, t+1), m, pp);
for i=1:t+1
    inverse_tb(i) = alpha^((i-1));%alpha^(i-1);
end
lamda_v=gf(0, m, pp);
accu_tb=gf(ones(1, t+1), m,pp);
for i=1:t+1
    accu_tb(i) = alpha^((i-1)*(nn-n+1));
end
zero = gf(0, m, pp);
error = zeros(2,n);
for i=1:n
    %accu_tb=accu_tb.*inverse_tb;
    lamda_v=lamda*accu_tb';
    accu_tb=accu_tb.*inverse_tb;
    if(lamda_v==zero)
        error(1,i)=1;
    end
end
%--------------------------------------------------------------------------
% Forney's algorithm
% find the error magnitudes using Forney's algorithm. This algorithm
% allows error magnitudes to be determined without matrix inversion. For
% RiBM, the omega term must be shifted by a power of 2*t.
%--------------------------------------------------------------------------
% the derivative of lamda comes out to be lamda with only the odd terms
% considered. generate the index vector...
even=floor(t/2)*2;
if(even==t)
    odd=t-1;
else
    odd=t;
end
%inverse table
inverse_tb = gf(zeros(1, t+1), m, pp);
for i=1:3*t
    inverse_tb(i) = alpha^(i-1);%alpha^(-i+1)
end
lamda_ov=gf(0, m, pp);
omega_v=gf(0, m, pp);
%accu_tb=gf(ones(1, t+1), m,pp);
accu_tb1=gf(ones(1, 3*t), m, pp);
% for i=1:t+1
%     accu_tb(i) = alpha^((i-1)*(nn-n+1));
% end
for i=1:t*3
    accu_tb1(i) = alpha^((i-1)*(nn-n+1));
end
% shift the exponents of omega by 2*t for RiBM (equation 12 in paper)
omega = [zeros(1,2*t),omega];
for i=1:n
    lamda_ov=lamda(2:2:odd+1)*accu_tb1(2:2:odd+1)';
    omega_v=omega*accu_tb1';    
    %accu_tb=accu_tb.*inverse_tb(1:t+1);
    accu_tb1=accu_tb1.*inverse_tb;    
     
    ev=(omega_v/lamda_ov)*alpha^(b*(nn-n+i));
    %if(error(1,n-i+1) == 1)
    if(error(1,i) == 1)
        %ev=(omega_v/lamda_ov)*alpha^(b*(nn-n+i));%alpha^b*(1-i)
        %error(2, n-i+1)=double(ev.x);
        error(2,i) = double(ev.x);
    end
end
%--------------------------------------------------------------------------
% Apply corrections - and display the results
%--------------------------------------------------------------------------
disp(['the original code is         : ', num2str(double(code.x))]);
disp(['the received code is         : ', num2str(double(reccode.x))]);
found = find(error(1,:)~=0);
disp(['found error(s) at location(s): ',num2str(found)]);
disp(['calulated error magnitudes   : ', num2str(error(2,found))]);
reccode(found) = reccode(found) - gf(error(2,found),m);
disp(['the corrected code is        : ', num2str(double(reccode.x))]);
