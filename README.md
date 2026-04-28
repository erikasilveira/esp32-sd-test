# 📟 ESP32 + Módulo SD — Teste com Dados Simulados

Projeto inicial de aprendizado com ESP32, testando leitura e escrita em cartão SD via protocolo SPI usando o Arduino IDE.

---

## 🧰 Hardware Utilizado

- ESP32 Dev Module
- Módulo SD Card (3.3V, sem regulador de tensão)
- Cartão MicroSD (FAT32)
- Protoboard + jumpers

---

## 🔌 Conexões (Pinout)

| Módulo SD | ESP32 | GPIO |
|-----------|-------|------|
| 3.3V      | 3.3V  | —    |
| GND       | GND   | —    |
| CS        | D4    | GPIO 4 |
| MOSI      | D23   | GPIO 23 |
| CLK       | D18   | GPIO 18 |
| MISO      | D19   | GPIO 19 |

> ⚠️ **Obs:** O pino CS foi movido do GPIO 2 para o GPIO 4, pois o GPIO 2 interfere no boot do ESP32.

---

## 💻 Ambiente de Desenvolvimento

- **IDE:** Arduino IDE 2.x
- **Suporte ESP32:** Pacote da Espressif Systems instalado via Boards Manager
  - URL: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`
- **Placa selecionada:** ESP32 Dev Module
- **Baud rate do Serial Monitor:** 115200

---

## 📄 O que o código faz

O sketch `teste_sd.ino` realiza as seguintes etapas:

1. Inicializa a comunicação SPI com o módulo SD (4MHz para melhor compatibilidade)
2. Cria um arquivo `/dados.txt` no cartão
3. Escreve um cabeçalho CSV e 10 linhas de dados simulados de sensores (temperatura e umidade com valores aleatórios)
4. Fecha o arquivo
5. Reabre e lê o conteúdo de volta, exibindo no Serial Monitor
6. Exibe o tamanho do cartão

### Exemplo de saída esperada no Serial Monitor

```
=== Teste Módulo SD ===
SD inicializado com sucesso!
Arquivo gravado com sucesso!

--- Conteúdo do arquivo ---
timestamp,temperatura,umidade
0,23.4,67.2
5000,28.1,55.0
...

Tamanho do cartão: 1893 MB
```

---

## ⚠️ Problemas encontrados e soluções

| Problema | Causa | Solução |
|----------|-------|---------|
| SD não detectado | Cartão formatado em FAT (não FAT32) | Reformatar em FAT32 |
| SD não detectado | GPIO 2 interfere no boot | Mover CS para GPIO 4 |
| Upload travado | GPIO 2 em HIGH durante boot | Apertar botão BOOT durante upload |
| Serial Monitor vazio | Monitor aberto antes do boot | Apertar botão RESET (EN) com monitor aberto |
| Timeout na inicialização | Frequência SPI muito alta | Usar 4MHz: `SD.begin(CS_PIN, SPI, 4000000)` |

---

## 📦 Bibliotecas utilizadas

Nativas do pacote ESP32 para Arduino — não é necessário instalar nada extra:

- `SPI.h`
- `SD.h`

---

## 🚀 Como usar

1. Monte o circuito conforme o pinout acima
2. Formate o cartão MicroSD em **FAT32**
3. Abra o arquivo `teste_sd.ino` no Arduino IDE
4. Selecione a placa **ESP32 Dev Module** e a porta correta em **Tools**
5. Clique em **Upload** (se travar, segure o botão **BOOT** da placa)
6. Abra o **Serial Monitor** (Ctrl+Shift+M) em **115200 baud**
7. Pressione o botão **RESET (EN)** da placa para ver a saída completa
