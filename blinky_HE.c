// Simple LED blink
// 08-Aug-2016 19:28 - WNixaloy

const int led = LED_BUILTIN;

void setup() {
    pinMode(led, OUTPUT);
}

void dot() {
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led, LOW);
    delay(70);
}

void dash() {
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(100);
}

void space() {
    digitalWrite(led, LOW);
    delay(160);
}

void loop() {
    void Hakan();
    void Elina();
    void lspace();

    Hakan();
    lspace();
//  et
    dot();
    space();
    dash();

    lspace();
    Elina();
    lspace();
    sont();
    lspace();
    super();
    lspace();
    cool();
    lspace();
    lspace();
    lspace();
    cest();
    lspace();
    francais();

    for (int i = 0; i < 10; i++) {
        lspace();
    }
}

void Hakan() {
    for (int i = 0; i < 4; i++) {
        dot();
    }
    space();
    dot();
    dash();
    space();
    dash();
    dot();
    dash();
    space();
    dot();
    dash();
    space();
    dash();
    dot();
}

void Elina() {
    dot();
    space();
    dot();
    dash();
    dot();
    dot();
    space();
    dot();
    dot();
    space();
    dash();
    dot();
    space();
    dot();
    dash();
}

void sont() {
    dot();
    dot();
    dot();
    space();
    dash();
    dash();
    dash();
    space();
    dash();
    dot();
    space();
    dash();
}

void super() {
    dot();
    dot();
    dot();
    space();
    dot();
    dot();
    dash();
    space();
    dot();
    dash();
    dash();
    dot();
    space();
    dot();
    space();
    dot();
    dash();
    dot();
}

void cool() {
    dash();
    dot();
    dash();
    dot();
    space();
    dash();
    dash();
    dash();
    space();
    dash();
    dash();
    dash();
    space();
    dot();
    dash();
    dot();
    dot();
}

void cest() {
    dash();
    dot();
    dash();
    space();
    dot();
    dash();
    dash();
    dash();
    dash();
    dot();
    space();
    dot();
    space();
    dot();
    dot();
    dot();
    space();
    dash();
}

void francais() {
    dot();
    dot();
    dash();
    dot();
    space();
    dot();
    dash();
    dot();
    space();
    dot();
    dash();
    space();
    dash();
    dot();
    space();
    dash();
    dot();
    dash();
    dot();
    space();
    dot();
    dash();
    space();
    dot();
    dot();
    space();
    dot();
    dot();
    dot();
}

void lspace() {
    space();
    space();
}

//  digitalWrite(led, HIGH);
//  delay(200);
//  digitalWrite(led, LOW);
//  delay(50);
