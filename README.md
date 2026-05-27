# Pomodoro Timer — Arduino

![Arduino](https://img.shields.io/badge/Arduino-Uno_R3-00979D?logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/C%2B%2B-Arduino_IDE-blue)
![Simulation](https://img.shields.io/badge/Simulado-Tinkercad-orange)
![License](https://img.shields.io/badge/License-MIT-green)

Temporizador Pomodoro com Arduino, LEDs e potenciômetro.

## Componentes

| Ref | Componente | Qtd |
|-----|-----------|-----|
| U1 | Arduino Uno | 1 |
| D1 | LED vermelho | 1 |
| D2 | LED verde | 1 |
| R1, R2 | Resistor 220 Ω | 2 |
| R3 | Resistor 10 kΩ | 1 |
| S1 | Botão | 1 |
| Rpot2 | Potenciômetro 250 kΩ | 1 |

## Pinagem

| Pino | Função |
|------|--------|
| D10 (PWM) | LED vermelho — fase work |
| D9 (PWM) | LED verde — fase pausa |
| D2 | Botão (INPUT_PULLUP) |
| A0 | Potenciômetro |

<img width="2200" height="1700" alt="Pomodoro Timer-2-1" src="https://github.com/user-attachments/assets/2034c952-7f57-48be-9f77-0991fa0825e4" />

<img width="319" height="215" alt="image" src="https://github.com/user-attachments/assets/2a29e71b-8f4e-484d-9eb4-4ab85a2c8f33" />

---

## ⚙️ Como funciona

### 🟢 Fase WORK
O LED verde acende e inicia a contagem definida pelo usuário antes de apertar o botão. Assim que chegar no final, entrará na fase pausa.

### 🔴 Fase PAUSA
O LED vermelho acende indicando um momento de descanso. Seu cálculo é relativo à minutagem da fase WORK.

### 🖥️ Monitor Serial
Abra o Serial Monitor a **9600 baud** para ver:
- Menu com duração de work e pausa (atualiza ao girar o pot)
- Contagem regressiva segundo a segundo
- Aviso de troca de fase

---

## ✨ Funcionalidades

- **Ajuste dinâmico** — potenciômetro configura duração do work de 5 a 30 min
- **Botão de controle** — toggle entre menu e execução; segundo clique para o timer
- **Feedback serial** — menu, contagem regressiva e troca de fase no monitor
- **Ciclos automáticos** — work → pausa → work sem intervenção

---

## 🚀 Como usar

```bash
# 1. Clone o repositório
git clone https://github.com/seu-usuario/pomodoro-timer.git

# 2. Abra no Arduino IDE
#    File → Open → pomodoro_timer.ino

# 3. Selecione a placa e porta
#    Board: Arduino Uno
#    Port:  COMX (Windows) ou /dev/ttyUSBX (Linux/Mac)

# 4. Faça o upload (Ctrl+U)

# 5. Abra o Serial Monitor (9600 baud)
#    Gire o potenciômetro para ajustar o tempo
#    Pressione o botão para iniciar
```

---

## 📁 Estrutura do projeto

```
pomodoro-timer/
├── pomodoro_timer.ino   # código principal
├── Pomodoro_Timer.pdf   # esquemático (exportado do Tinkercad)
└── README.md
```

---

## 📜 Licença

Distribuído sob a licença MIT. Veja `LICENSE` para mais informações.
