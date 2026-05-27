#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char titulo[100];
    char cor_fundo[50];
    char cor_texto[50];
    FILE *arquivo;

    printf("=== GERADOR DE PAGINA HTML ===\n\n");

    // Lendo o título da página
    printf("Digite o titulo da pagina: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strcspn(titulo, "\n")] = '\0'; // Remove a quebra de linha do final

    // Lendo a cor de fundo
    printf("Digite a cor de fundo (ex: blue, red, #333333): ");
    fgets(cor_fundo, sizeof(cor_fundo), stdin);
    cor_fundo[strcspn(cor_fundo, "\n")] = '\0';

    // Lendo a cor do texto
    printf("Digite a cor do texto (ex: white, yellow, black): ");
    fgets(cor_texto, sizeof(cor_texto), stdin);
    cor_texto[strcspn(cor_texto, "\n")] = '\0';

    // Criando e abrindo o arquivo HTML para escrita
    arquivo = fopen("pagina.html", "w");

    // Verificando se o arquivo foi criado com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo HTML!\n");
        return 1;
    }

    // Escrevendo a estrutura do HTML no arquivo
    fprintf(arquivo, "<!DOCTYPE html>\n");
    fprintf(arquivo, "<html lang=\"pt-BR\">\n");
    fprintf(arquivo, "<head>\n");
    fprintf(arquivo, "    <meta charset=\"UTF-8\">\n");
    fprintf(arquivo, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    fprintf(arquivo, "    <title>%s</title>\n", titulo);
    fprintf(arquivo, "    <style>\n");
    fprintf(arquivo, "        body {\n");
    fprintf(arquivo, "            background-color: %s;\n", cor_fundo);
    fprintf(arquivo, "            color: %s;\n", cor_texto);
    fprintf(arquivo, "            font-family: Arial, sans-serif;\n");
    fprintf(arquivo, "            display: flex;\n");
    fprintf(arquivo, "            flex-direction: column;\n");
    fprintf(arquivo, "            justify-content: center;\n");
    fprintf(arquivo, "            align-items: center;\n");
    fprintf(arquivo, "            height: 100vh;\n");
    fprintf(arquivo, "            margin: 0;\n");
    fprintf(arquivo, "        }\n");
    fprintf(arquivo, "    </style>\n");
    fprintf(arquivo, "</head>\n");
    fprintf(arquivo, "<body>\n");
    fprintf(arquivo, "    <h1>%s</h1>\n", titulo);
    fprintf(arquivo, "    <p>Esta pagina foi gerada dinamicamente usando um programa em C!</p>\n");
    fprintf(arquivo, "</body>\n");
    fprintf(arquivo, "</html>\n");

    // Fechando o arquivo
    fclose(arquivo);

    printf("\nSucesso! O arquivo 'pagina.html' foi gerado na mesma pasta do programa.\n");

    return 0;
}