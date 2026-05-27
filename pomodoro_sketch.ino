int workPin = 10;
int pausePin = 9;
int buttonPin = 2;
int potPin = A0;
bool loopingAtivo = false;
int ultimoEstadoBotao = HIGH;
unsigned long ultimoTempo = 0;
bool faseWork = true;
unsigned long ultimoPrint = 0;
unsigned long ultimoMenu = 0;
int ultimoWorkMin = -1;

void setup() {
  pinMode(workPin, OUTPUT);
  pinMode(pausePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  limparConsole();
  mostrarMenu();
}

void limparConsole() {
  for (int i = 0; i < 50; i++) Serial.println();
}

void mostrarMenu() {
  unsigned long tempoWork  = map(analogRead(potPin), 0, 1023, 300000, 1800000);
  unsigned long tempoPause = tempoWork / 4;
  int workMin  = tempoWork / 60000;
  int pauseMin = tempoPause / 60000;

  limparConsole();
  Serial.println("============================");
  Serial.println("     POMODORO TIMER");
  Serial.println("============================");
  Serial.println("  Gire o pot para ajustar");
  Serial.println("  Pressione o botao p/ iniciar");
  Serial.println("----------------------------");
  Serial.print("  Work:  "); Serial.print(workMin);  Serial.println(" min");
  Serial.print("  Pause: "); Serial.print(pauseMin); Serial.println(" min");
  Serial.println("============================");

  ultimoWorkMin = workMin;
}

void loop() {
  unsigned long tempoWork  = map(analogRead(potPin), 0, 1023, 300000, 1800000);
  unsigned long tempoPause = tempoWork / 5;
  int workMin = tempoWork / 60000;

  int estadoBotao = digitalRead(buttonPin);
  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH) {
    loopingAtivo = !loopingAtivo;
    ultimoTempo = millis();
    faseWork = true;
    limparConsole();
    if (loopingAtivo) {
      Serial.println("============================");
      Serial.println("     POMODORO INICIADO");
      Serial.println("============================");
      Serial.print("  Work:  "); Serial.print(tempoWork / 60000);  Serial.println(" min");
      Serial.print("  Pause: "); Serial.print(tempoPause / 60000); Serial.println(" min");
      Serial.println("============================");
      Serial.println();
    } else {
      ultimoWorkMin = -1;
      mostrarMenu();
    }
    delay(200);
  }
  ultimoEstadoBotao = estadoBotao;

  if (!loopingAtivo) {
    analogWrite(workPin, 0);
    analogWrite(pausePin, 0);
    if (workMin != ultimoWorkMin && millis() - ultimoMenu >= 300) {
      ultimoMenu = millis();
      mostrarMenu();
    }
    return;
  }

  int brilho = map(analogRead(potPin), 0, 1023, 50, 255);
  unsigned long tempoAtual = faseWork ? tempoWork : tempoPause;
  unsigned long decorrido  = millis() - ultimoTempo;

  if (decorrido >= tempoAtual) {
    ultimoTempo = millis();
    faseWork = !faseWork;
    limparConsole();
    Serial.println(faseWork ? "=== WORK ===" : "=== PAUSE ===");
    Serial.println();
  }

  if (millis() - ultimoPrint >= 1000) {
    ultimoPrint = millis();
    unsigned long restante = (tempoAtual - decorrido) / 1000;
    unsigned long min = restante / 60;
    unsigned long seg = restante % 60;
    Serial.print("  Faltam: ");
    if (min > 0) { Serial.print(min); Serial.print("m "); }
    if (seg < 10) Serial.print("0");
    Serial.print(seg);
    Serial.println("s");
  }

  if (faseWork) {
    analogWrite(workPin, brilho);
    analogWrite(pausePin, 0);
  } else {
    analogWrite(workPin, 0);
    analogWrite(pausePin, brilho);
  }
}