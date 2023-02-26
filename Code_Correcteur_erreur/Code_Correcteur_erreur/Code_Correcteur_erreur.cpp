// Code_Correcteur_erreur.cpp : Définit le point d'entrée de l'application.
//

#include "pch.h"
#include "framework.h"
#include "Code_Correcteur_erreur.h"
#include <stdio.h>
#include <assert.h>
#include <windows.h>

#define MAX_LOADSTRING 100

// Variables globales :
HINSTANCE hInst;                                // instance actuelle
WCHAR szTitle[MAX_LOADSTRING];                  // Texte de la barre de titre
WCHAR szWindowClass[MAX_LOADSTRING];            // nom de la classe de fenêtre principale
HANDLE serialHandle;

// Déclarations anticipées des fonctions incluses dans ce module de code :
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    //// TODO: Placez le code ici.

    // Constantes
    #define K_NB_BIT_INFO     12
    #define NB_MOTS_INFO      4096
    #define N_NB_BIT_MOT_CODE 23

    #define NB_COLUMN_A       11   
    #define NB_LINE_A         K_NB_BIT_INFO
    #define NB_COLUMN_G       N_NB_BIT_MOT_CODE   
    #define NB_LINE_G         K_NB_BIT_INFO
    #define NB_COLUMN_I       K_NB_BIT_INFO   
    #define NB_LINE_I         NB_MOTS_INFO
    #define NB_COLUMN_H       (K_NB_BIT_INFO + NB_COLUMN_A) 
    #define NB_LINE_H         NB_COLUMN_A

    // Déclaration des variables 
    int i, j, k, iBcl1, iBcl2;
    int p_min, p_min_temp, val_temp;

    // ----------
    // Matrices : 
    // ----------
    // Matrice generatrice
    // -------------------------------------------------1-------------------------------|------------------A----------------------|
    int G[NB_LINE_G][NB_COLUMN_G] = { { 1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,    1,  0, 1,	0,	1,	1,	1,	0,	0,	0,	1},
                                      { 0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,    1,  1, 1,	1,	1,	0,	0,	1,	0,	0,	1},
                                      { 0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,  0,    1,  1, 0,	1,	0,	0,	1,	0,	1,	0,	1},
                                      { 0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,  0,    1,  1, 0,	0,	0,	1,	1,	1,	0,	1,	1},
                                      { 0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,  0,    1,  1, 0,	0,	1,	1,	0,	1,	1,	0,	0},
                                      { 0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,  0,    0,  1, 1,	0,	0,	1,	1,	0,	1,	1,	0},
                                      { 0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,  0,    0,  0, 1,	1,	0,	0,	1,	1,	0,	1,	1},
                                      { 0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,  0,    1,  0, 1,	1,	0,	1,	1,	1,	1,	0,	0},
                                      { 0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,  0,    0,  1, 0,	1,	1,	0,	1,	1,	1,	1,	0},
                                      { 0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,  0,    0,  0, 1,	0,	1,	1,	0,	1,	1,	1,	1},
                                      { 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,  0,    1,  0, 1,	1,	1,	0,	0,	0,	1,	1,	0},
                                      { 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,  1,    0,  1, 0,	1,	1,	1,	0,	0,	0,	1,	1} };

    // Matrice mots informations
    int I[NB_LINE_I][NB_COLUMN_I];
    int H[NB_LINE_H][NB_COLUMN_H];

    // Matrices de calcules 
    int mul[NB_MOTS_INFO][N_NB_BIT_MOT_CODE];
    int A[NB_LINE_A][NB_COLUMN_A], A_trans[NB_COLUMN_A][NB_LINE_A];


    // Initialisation des mots infos 
    for (iBcl1 = 0; iBcl1 < NB_MOTS_INFO; iBcl1++)
    {
        val_temp = iBcl1;
        for (iBcl2 = K_NB_BIT_INFO - 1; iBcl2 >= 0 ; iBcl2--)
        {
            I[iBcl1][iBcl2] = val_temp % 2;
            val_temp = val_temp / 2;
        }
    }

    // Multiplication de matrice 
    for (i = 0; i < NB_MOTS_INFO; i++)
    {
        for (j = 0; j < 25; j++)
        {
            mul[i][j] = 0;
            for (k = 0; k < K_NB_BIT_INFO; k++)
            {
                mul[i][j] = (I[i][k] * G[k][j] + mul[i][j]) % 2;
            }
        }
    }

    // Calcule du poid min -> distance min 
    p_min = N_NB_BIT_MOT_CODE;
    p_min_temp = N_NB_BIT_MOT_CODE;
    for (i = 0; i < NB_MOTS_INFO; i++)
    {
        for (j = 0; j < N_NB_BIT_MOT_CODE; j++)
        {
            if (mul[i][j] == 1)
            {
                p_min_temp++;
            }
        }
        if ((p_min > p_min_temp) & (p_min_temp != 0))
        {
            p_min = p_min_temp;
        }
        p_min_temp = 0;
    }

    // Calcule de A
    for (i = NB_COLUMN_G - NB_COLUMN_A; i < NB_COLUMN_G; i++)
    {
        for (j = 0; j < NB_LINE_A; j++)
        {
            A[j][i - (NB_COLUMN_G - NB_COLUMN_A)] = G[j][i];
        }
    }

    // Calcule de H 
    // Calcule de la transposé de A
    for (i = 0; i < K_NB_BIT_INFO; i++)
    {
        for (j = 0; j < NB_COLUMN_A; j++)
        {
            A_trans[j][i] = A[i][j];
        }
    }


    // Fill H with A transposé
    for (i = 0; i < NB_COLUMN_A; i++)
    {
        for (j = 0; j < K_NB_BIT_INFO; j++)
        {
            H[i][j] = A_trans[i][j];
        }
    }

    // Fill H with ID matrice 
    // Fill all 0
    for (i = NB_LINE_A; i < NB_COLUMN_H; i++)
    {
        for (j = 0; j < NB_LINE_H; j++)
        {
            H[j][i] = 0;
        }
    }

    // Fill all 1
    j = 0;
    for (i = NB_LINE_A; i < NB_COLUMN_H; i++)
    {
        H[j][i] = 1;
        j++;
    }

    

 
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    // Initialise les chaînes globales
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CODECORRECTEURERREUR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Effectue l'initialisation de l'application :
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CODECORRECTEURERREUR));

    MSG msg;

    // Boucle de messages principale :
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FONCTION : MyRegisterClass()
//
//  OBJECTIF : Inscrit la classe de fenêtre.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CODECORRECTEURERREUR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CODECORRECTEURERREUR);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FONCTION : InitInstance(HINSTANCE, int)
//
//   OBJECTIF : enregistre le handle d'instance et crée une fenêtre principale
//
//   COMMENTAIRES :
//
//        Dans cette fonction, nous enregistrons le handle de l'instance dans une variable globale, puis
//        nous créons et affichons la fenêtre principale du programme.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Stocke le handle d'instance dans la variable globale

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FONCTION : WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  OBJECTIF : Traite les messages pour la fenêtre principale.
//
//  WM_COMMAND  - traite le menu de l'application
//  WM_PAINT    - Dessine la fenêtre principale
//  WM_DESTROY  - génère un message d'arrêt et retourne
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analyse les sélections de menu :
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                CloseHandle(serialHandle);
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Ajoutez ici le code de dessin qui utilise hdc...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Gestionnaire de messages pour la boîte de dialogue À propos de.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
