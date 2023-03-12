#pragma once

#include "Code_Golay.h"
#include <string>
#include <msclr\marshal_cppstd.h>
#include <bitset>
namespace GolayGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxSaisieMotsInfos;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBoxCodageMotsInfos;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxInsertionErreurs;
	private: System::Windows::Forms::Button^ buttonEnvoiLiaisonSerie;


	private: System::Windows::Forms::TextBox^ textBoxMessageBinaire;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxDecodageCorrection;
	private: System::Windows::Forms::Button^ buttonValidationSaisie;
	private: System::Windows::Forms::TextBox^ textBoxMessageCodeErreursBinaire;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBoxNumeroPortSerie;
	private: System::Windows::Forms::Label^ label7;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxMessageRecu;
	private: System::ComponentModel::IContainer^ components;

		   






	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxSaisieMotsInfos = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBoxCodageMotsInfos = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxInsertionErreurs = (gcnew System::Windows::Forms::TextBox());
			this->buttonEnvoiLiaisonSerie = (gcnew System::Windows::Forms::Button());
			this->textBoxMessageBinaire = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxDecodageCorrection = (gcnew System::Windows::Forms::TextBox());
			this->buttonValidationSaisie = (gcnew System::Windows::Forms::Button());
			this->textBoxMessageCodeErreursBinaire = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxNumeroPortSerie = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxMessageRecu = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Saisie du message à coder";
			// 
			// textBoxSaisieMotsInfos
			// 
			this->textBoxSaisieMotsInfos->Location = System::Drawing::Point(195, 34);
			this->textBoxSaisieMotsInfos->Name = L"textBoxSaisieMotsInfos";
			this->textBoxSaisieMotsInfos->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->textBoxSaisieMotsInfos->Size = System::Drawing::Size(669, 20);
			this->textBoxSaisieMotsInfos->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 178);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Codage des mots infos :";
			// 
			// textBoxCodageMotsInfos
			// 
			this->textBoxCodageMotsInfos->Enabled = false;
			this->textBoxCodageMotsInfos->Location = System::Drawing::Point(195, 178);
			this->textBoxCodageMotsInfos->Name = L"textBoxCodageMotsInfos";
			this->textBoxCodageMotsInfos->Size = System::Drawing::Size(669, 20);
			this->textBoxCodageMotsInfos->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(34, 243);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(82, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Insertion erreurs";
			// 
			// textBoxInsertionErreurs
			// 
			this->textBoxInsertionErreurs->Location = System::Drawing::Point(195, 240);
			this->textBoxInsertionErreurs->Name = L"textBoxInsertionErreurs";
			this->textBoxInsertionErreurs->Size = System::Drawing::Size(669, 20);
			this->textBoxInsertionErreurs->TabIndex = 7;
			// 
			// buttonEnvoiLiaisonSerie
			// 
			this->buttonEnvoiLiaisonSerie->Location = System::Drawing::Point(195, 365);
			this->buttonEnvoiLiaisonSerie->Name = L"buttonEnvoiLiaisonSerie";
			this->buttonEnvoiLiaisonSerie->Size = System::Drawing::Size(669, 48);
			this->buttonEnvoiLiaisonSerie->TabIndex = 8;
			this->buttonEnvoiLiaisonSerie->Text = L"Validation erreurs et envoi sur la liaison série";
			this->buttonEnvoiLiaisonSerie->UseVisualStyleBackColor = true;
			this->buttonEnvoiLiaisonSerie->Click += gcnew System::EventHandler(this, &MyForm::buttonEnvoiLiaisonSerie_Click);
			// 
			// textBoxMessageBinaire
			// 
			this->textBoxMessageBinaire->Enabled = false;
			this->textBoxMessageBinaire->Location = System::Drawing::Point(195, 75);
			this->textBoxMessageBinaire->Name = L"textBoxMessageBinaire";
			this->textBoxMessageBinaire->Size = System::Drawing::Size(669, 20);
			this->textBoxMessageBinaire->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(36, 78);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(138, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Message à coder en binaire";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(34, 493);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Décodage";
			// 
			// textBoxDecodageCorrection
			// 
			this->textBoxDecodageCorrection->Enabled = false;
			this->textBoxDecodageCorrection->Location = System::Drawing::Point(195, 490);
			this->textBoxDecodageCorrection->Name = L"textBoxDecodageCorrection";
			this->textBoxDecodageCorrection->Size = System::Drawing::Size(669, 20);
			this->textBoxDecodageCorrection->TabIndex = 12;
			// 
			// buttonValidationSaisie
			// 
			this->buttonValidationSaisie->Location = System::Drawing::Point(195, 107);
			this->buttonValidationSaisie->Name = L"buttonValidationSaisie";
			this->buttonValidationSaisie->Size = System::Drawing::Size(669, 48);
			this->buttonValidationSaisie->TabIndex = 13;
			this->buttonValidationSaisie->Text = L"Validation Saisie";
			this->buttonValidationSaisie->UseVisualStyleBackColor = true;
			this->buttonValidationSaisie->Click += gcnew System::EventHandler(this, &MyForm::buttonValidationSaisie_Click);
			// 
			// textBoxMessageCodeErreursBinaire
			// 
			this->textBoxMessageCodeErreursBinaire->Enabled = false;
			this->textBoxMessageCodeErreursBinaire->Location = System::Drawing::Point(195, 293);
			this->textBoxMessageCodeErreursBinaire->Name = L"textBoxMessageCodeErreursBinaire";
			this->textBoxMessageCodeErreursBinaire->Size = System::Drawing::Size(669, 20);
			this->textBoxMessageCodeErreursBinaire->TabIndex = 14;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(36, 296);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(139, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Message codé avec erreurs";
			// 
			// textBoxNumeroPortSerie
			// 
			this->textBoxNumeroPortSerie->Location = System::Drawing::Point(51, 393);
			this->textBoxNumeroPortSerie->Name = L"textBoxNumeroPortSerie";
			this->textBoxNumeroPortSerie->Size = System::Drawing::Size(103, 20);
			this->textBoxNumeroPortSerie->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(48, 365);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(90, 13);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Numero port série";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(34, 457);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(74, 13);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Message reçu";
			// 
			// textBoxMessageRecu
			// 
			this->textBoxMessageRecu->Enabled = false;
			this->textBoxMessageRecu->Location = System::Drawing::Point(195, 450);
			this->textBoxMessageRecu->Name = L"textBoxMessageRecu";
			this->textBoxMessageRecu->Size = System::Drawing::Size(669, 20);
			this->textBoxMessageRecu->TabIndex = 19;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(966, 534);
			this->Controls->Add(this->textBoxMessageRecu);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBoxNumeroPortSerie);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxMessageCodeErreursBinaire);
			this->Controls->Add(this->buttonValidationSaisie);
			this->Controls->Add(this->textBoxDecodageCorrection);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxMessageBinaire);
			this->Controls->Add(this->buttonEnvoiLiaisonSerie);
			this->Controls->Add(this->textBoxInsertionErreurs);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBoxCodageMotsInfos);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBoxSaisieMotsInfos);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Projet Code Correcteur";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		initialization();
		textBoxNumeroPortSerie->Text = "COM3";
	}
	private: System::Void buttonValidationSaisie_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string mot_info_saisi = msclr::interop::marshal_as<std::string>(textBoxSaisieMotsInfos->Text);
		std::string mot_info_saisi_binaire = "";
		std::string mot_code_golay = "";
		
		int mot_info_a_coder[K_NB_BIT_INFO] = { 0 };
		int mot_code[N_NB_BIT_MOT_CODE] = { 0 };

		for (int i = 0; i < mot_info_saisi.size(); i++) {
			// Formation mot info sous forme mot_info[K_NB_BIT_INFO]
			for (int j = K_NB_BIT_INFO - 1; j >= 0; j--) {
				mot_info_a_coder[j] = (mot_info_saisi[i] >> (7 - j)) & 0x1;
				mot_info_saisi_binaire += std::to_string(mot_info_a_coder[j]);
			}

			encode(mot_info_a_coder, mot_code);

			// Formation string contenant le mot code ('1' et '0' à la suite)
			for (int k = 0; k < N_NB_BIT_MOT_CODE; k++) {
				mot_code_golay = mot_code_golay + std::to_string(mot_code[k]);
			}
		}

		System::String^ mot_info_sais_syst_str = gcnew String(mot_info_saisi_binaire.c_str());
		textBoxMessageBinaire->Text = mot_info_sais_syst_str;

		System::String^ mot_code_golay_syst_str = gcnew String(mot_code_golay.c_str());
		textBoxCodageMotsInfos->Text = mot_code_golay_syst_str;

		std::string errors(mot_code_golay.length(), '0');
		textBoxInsertionErreurs->Text = gcnew String(errors.c_str());
	}
	private: System::Void buttonEnvoiLiaisonSerie_Click(System::Object^ sender, System::EventArgs^ e) {
		// Ajout erreurs
		std::string message = msclr::interop::marshal_as<std::string>(textBoxCodageMotsInfos->Text);
		std::string errors = msclr::interop::marshal_as<std::string>(textBoxInsertionErreurs->Text);
		std::string message_xor_errors(message.length(), '0');

		for (int i = 0; i < message.length(); i++) {
			message_xor_errors[i] = ((message[i] - '0') ^ (errors[i] - '0')) + '0';
		}

		textBoxMessageCodeErreursBinaire->Text = gcnew String(message_xor_errors.c_str());
		
		serialPort1->BaudRate = 9600;
		//serialPort1->PortName = "COM3";
		serialPort1->PortName = textBoxNumeroPortSerie->Text;
		serialPort1->Open();

		serialPort1->WriteLine(textBoxMessageCodeErreursBinaire->Text);

		textBoxMessageRecu->Text = serialPort1->ReadLine();
		serialPort1->Close();

		textBoxDecodageCorrection->Text = String::Empty;

		int number_of_rx_bytes = msclr::interop::marshal_as<std::string>(textBoxMessageRecu->Text).length() / N_NB_BIT_MOT_CODE;
		std::string decoded_string = "";

		std::string message_recu = msclr::interop::marshal_as<std::string>(textBoxMessageRecu->Text);
		for (int i = 0; i < number_of_rx_bytes; i++) {
			int coded_word[N_NB_BIT_MOT_CODE] = { 0 };

			for (int j = 0; j < N_NB_BIT_MOT_CODE; j++) {
				// get bit value
				coded_word[j] = message_recu[j + (i* N_NB_BIT_MOT_CODE)] - '0';
			}

			int decoded_word[K_NB_BIT_INFO] = { 0 };
			decode(coded_word, decoded_word);

			int caractere = 0;
			for (int c = 0; c < K_NB_BIT_INFO; c++) {
				caractere += decoded_word[c] << (7 - c);
			}

			decoded_string += caractere;
		}
		textBoxDecodageCorrection->Text = gcnew String(decoded_string.c_str());
	}

};
}
