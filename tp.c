#include <stdio.h>
#include <stdlib.h>

// Fonctions pour les exercices
void sumMatrices();
void productMatrices();
void sequentialSearch();
int recursiveMultiplication(int a, int b);
void isSorted();
void findMedian();
void reverseArray();
void crossProduct();
void vectorMatrixProduct();

// Fonction principale pour le menu
int main() {
    int choice;

    do {
        printf("\n--- MENU DES EXERCICES ---\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche sequentielle dans un tableau\n");
        printf("4. Multiplication recursive (a * b)\n");
        printf("5. Tester si un tableau est trie\n");
        printf("6. Trouver le median dans un tableau\n");
        printf("7. Inverser un tableau\n");
        printf("8. Produit vectoriel\n");
        printf("9. Produit vecteur x matrices\n");
        printf("0. Quitter\n");
        printf("--------------------------\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sumMatrices();
                break;
            case 2:
                productMatrices();
                break;
            case 3:
                sequentialSearch();
                break;
            case 4: {
                int a, b;
                printf("Entrez a : ");
                scanf("%d", &a);
                printf("Entrez b : ");
                scanf("%d", &b);
                if (a >= 0 && b >= 0) {
                    printf("Resultat : %d\n", recursiveMultiplication(a, b));
                } else {
                    printf("a et b doivent etre positifs.\n");
                }
                break;
            }
            case 5:
                isSorted();
                break;
            case 6:
                findMedian();
                break;
            case 7:
                reverseArray();
                break;
            case 8:
                crossProduct();
                break;
            case 9:
                vectorMatrixProduct();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choice != 0);

    return 0;
}

// ------------------------------------
//          1. Somme de matrices
// ------------------------------------
void sumMatrices() {
    int rows, cols, i, j;

    printf("Entrez le nombre de lignes : ");
    scanf("%d", &rows);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &cols);

    int mat1[rows][cols], mat2[rows][cols], sum[rows][cols];

    printf("Entrez les elements de la premiere matrice :\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Entrez les elements de la deuxieme matrice :\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Calcul de la somme
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("La somme des deux matrices est :\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

// ------------------------------------
//         2. Produit de matrices
// ------------------------------------
void productMatrices() {
    int rows1, cols1, rows2, cols2, i, j, k;

    printf("Entrez le nombre de lignes de la premiere matrice : ");
    scanf("%d", &rows1);
    printf("Entrez le nombre de colonnes de la premiere matrice : ");
    scanf("%d", &cols1);

    printf("Entrez le nombre de lignes de la deuxieme matrice : ");
    scanf("%d", &rows2);
    printf("Entrez le nombre de colonnes de la deuxieme matrice : ");
    scanf("%d", &cols2);

    if (cols1 != rows2) {
        printf("Erreur : Le nombre de colonnes de la premiere matrice doit etre egal au nombre de lignes de la deuxieme.\n");
        return;
    }

    int mat1[rows1][cols1], mat2[rows2][cols2], product[rows1][cols2];

    printf("Entrez les elements de la premiere matrice :\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Entrez les elements de la deuxieme matrice :\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Initialiser la matrice produit a zero
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            product[i][j] = 0;
        }
    }

    // Calcul du produit
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            for (k = 0; k < cols1; k++) {
                product[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Le produit des deux matrices est :\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
}

// ------------------------------------
//     3. Recherche sequentielle
// ------------------------------------
void sequentialSearch() {
    int n, i, target, found = 0;

    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);

    int arr[n];
    printf("Entrez les elements du tableau :\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Entrez l'element a rechercher : ");
    scanf("%d", &target);

    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Element trouve a l'indice %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element non trouve dans le tableau.\n");
    }
}

// ------------------------------------
//   4. Multiplication recursive (a * b)
// ------------------------------------
int recursiveMultiplication(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a + recursiveMultiplication(a, b - 1);
}

// ------------------------------------
//     5. Tester si un tableau est trie
// ------------------------------------
void isSorted() {
    int n, i, sorted = 1;

    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);

    int arr[n];
    printf("Entrez les elements du tableau :\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            sorted = 0;
            break;
        }
    }

    if (sorted) {
        printf("Le tableau est trie.\n");
    } else {
        printf("Le tableau n'est pas trie.\n");
    }
}

// ------------------------------------
//     6. Trouver le median
// ------------------------------------
void findMedian() {
    int n, i, j, temp;

    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);

    int arr[n];
    printf("Entrez les elements du tableau :\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Tri du tableau (Bubble Sort pour la simplicite)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    if (n % 2 == 1) {
        printf("Le median est : %d\n", arr[n / 2]);
    } else {
        double median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        printf("Le median est : %.2f\n", median);
    }
}

// ------------------------------------
//        7. Inverser un tableau
// ------------------------------------
void reverseArray() {
    int n, i;

    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);

    int arr[n];
    printf("Entrez les elements du tableau :\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Inversion du tableau
    for (i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("Le tableau inverse est :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ------------------------------------
//        8. Produit vectoriel
// ------------------------------------
void crossProduct() {
    int vec1[3], vec2[3], result[3], i;

    printf("Entrez les 3 composantes du premier vecteur (i j k) :\n");
    for (i = 0; i < 3; i++) {
        scanf("%d", &vec1[i]);
    }

    printf("Entrez les 3 composantes du deuxieme vecteur (i j k) :\n");
    for (i = 0; i < 3; i++) {
        scanf("%d", &vec2[i]);
    }

    // Calcul du produit vectoriel
    result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];

    printf("Le produit vectoriel est : (%d, %d, %d)\n", result[0], result[1], result[2]);
}

// ------------------------------------
//      9. Produit vecteur x matrices
// ------------------------------------
void vectorMatrixProduct() {
    int vecSize, rows, cols, i, j;

    printf("Entrez la taille du vecteur : ");
    scanf("%d", &vecSize);

    printf("Entrez le nombre de lignes de la matrice : ");
    scanf("%d", &rows);
    printf("Entrez le nombre de colonnes de la matrice : ");
    scanf("%d", &cols);

    if (vecSize != rows) {
        printf("Erreur : La taille du vecteur doit etre egale au nombre de lignes de la matrice.\n");
        return;
    }

    int vector[vecSize], matrix[rows][cols], result[cols];

    printf("Entrez les elements du vecteur :\n");
    for (i = 0; i < vecSize; i++) {
        scanf("%d", &vector[i]);
    }

    printf("Entrez les elements de la matrice :\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Initialiser le tableau resultat a zero
    for (j = 0; j < cols; j++) {
        result[j] = 0;
    }

    // Calcul du produit vecteur x matrice
    for (j = 0; j < cols; j++) {
        for (i = 0; i < rows; i++) {
            result[j] += vector[i] * matrix[i][j];
        }
    }

    printf("Le produit vecteur x matrice est : (");
    for (j = 0; j < cols; j++) {
        printf("%d%s", result[j], (j == cols - 1) ? "" : ", ");
    }
    printf(")\n");
}
