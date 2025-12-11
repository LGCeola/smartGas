// =======================
// SmartGass Final v1.0
// =======================

// CONFIGURAÇÕES
const int MQ2_PIN = A0;          // Pino analógico do sensor
const int BUZZER_PIN = 8;        // Pino do buzzer passivo
const int SAMPLES = 8;           // Número de amostras para média móvel
const int THRESHOLD_ON = 400;    // Valor para acionar o alarme
const int THRESHOLD_OFF = 350;   // Histerese para desligar o alarme
const unsigned long DEBOUNCE_MS = 800; // Tempo mínimo entre mudanças

// VARIÁVEIS
int samples[SAMPLES];
int idx = 0;
unsigned long lastChange = 0;
bool alarmState = false;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.println("Iniciando SmartGas...");
  Serial.println("Aguardando aquecimento do sensor...");

  // Inicializa o array de amostras com leituras válidas
  for (int i = 0; i < SAMPLES; i++) {
    samples[i] = analogRead(MQ2_PIN);
    delay(150); // Pequeno delay para aquecimento do sensor
  }

  Serial.println("Sensor pronto!");
  Serial.println("----------------------------");
}

int readFiltered() {
  // Atualiza a amostra atual
  samples[idx] = analogRead(MQ2_PIN);
  idx = (idx + 1) % SAMPLES;

  // Calcula média móvel
  long sum = 0;
  for (int i = 0; i < SAMPLES; i++) sum += samples[i];
  return sum / SAMPLES;
}

void loop() {
  int value = readFiltered();

  // Imprime valores no Serial Monitor
  Serial.print("MQ-2 (filtrado): ");
  Serial.println(value);

  unsigned long now = millis();

  // Verifica se o alarme deve ser ligado
  if (!alarmState && value >= THRESHOLD_ON && (now - lastChange) > DEBOUNCE_MS) {
    alarmState = true;
    lastChange = now;
    tone(BUZZER_PIN, 2500); // Liga buzzer
    Serial.println("ALERTA: Vazamento detectado!");
  } 
  // Verifica se o alarme deve ser desligado
  else if (alarmState && value <= THRESHOLD_OFF && (now - lastChange) > DEBOUNCE_MS) {
    alarmState = false;
    lastChange = now;
    noTone(BUZZER_PIN); // Desliga buzzer
    Serial.println("ALERTA: Tudo em ordem.");
  }

  delay(200); // Pequeno delay para estabilidade
}
