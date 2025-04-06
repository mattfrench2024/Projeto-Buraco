#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Função para gerar a carta no formato "N-99-B"
std::string gerarCarta(int naipe, int numero, int baralho) {
    std::stringstream ss;
    ss << naipe << "-" << (numero < 10 ? "0" : "") << numero << "-" << baralho;
    return ss.str();
}

// Função para criar o baralho duplo
void criarBaralho(std::vector<std::string>& baralho) {
    for (int b = 1; b <= 2; ++b) {  // Dois baralhos
        for (int n = 1; n <= 4; ++n) {  // Quatro naipes
            for (int num = 1; num <= 13; ++num) {  // 13 valores de carta
                baralho.push_back(gerarCarta(n, num, b));
            }
        }
    }
}

// Função para embaralhar o baralho
void embaralhar(std::vector<std::string>& baralho) {
    std::random_shuffle(baralho.begin(), baralho.end());
}

// Função para distribuir as cartas para os jogadores
void distribuirParaJogadores(const std::vector<std::string>& baralho, std::vector<std::vector<std::string>>& jogadores) {
    int index = 0;
    for (int j = 0; j < 4; ++j) {  // Para cada jogador
        for (int c = 0; c < 11; ++c) {  // Cada jogador recebe 11 cartas
            jogadores[j][c] = baralho[index++];
        }
    }
}

// Função para exibir as mãos dos jogadores
void exibirMao(const std::vector<std::vector<std::string>>& jogadores) {
    for (int j = 0; j < 4; ++j) {  // Para cada jogador
        std::cout << "Jogador " << j + 1 << ": ";
        for (const auto& carta : jogadores[j]) {  // Exibe as cartas do jogador
            std::cout << carta << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));  // Inicializa o gerador de números aleatórios

    std::vector<std::string> baralho;  // Baralho duplo
    criarBaralho(baralho);  // Criação do baralho

    embaralhar(baralho);  // Embaralha o baralho

    // Vetor de mãos dos jogadores, 4 jogadores com 11 cartas cada
    std::vector<std::vector<std::string>> jogadores(4, std::vector<std::string>(11));  
    distribuirParaJogadores(baralho, jogadores);  // Distribui as cartas para os jogadores

    exibirMao(jogadores);  // Exibe as mãos dos jogadores

    return 0;
}
