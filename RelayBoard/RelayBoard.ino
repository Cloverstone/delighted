
const int pins[] = {2,3,4,5,6,7,8,9};    // the number of the pushbutton pin


String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
void setup() {

  Serial.begin(9600);
 
  for (int i=0; i<sizeof pins/sizeof pins[0]; i++) {
    pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i],HIGH);
  }
}

void execute(String inputString) {
 
  if(inputString.startsWith("-")){    
    int relay = inputString.substring(1,2).toInt();
    digitalWrite(relay,HIGH);

  }

  if(inputString.startsWith("+")){    
    int relay = inputString.substring(1,2).toInt();
    digitalWrite(relay,LOW);

  }
  
  if(inputString.startsWith("L")){    
    int relay = inputString.substring(1,2).toInt();
    digitalWrite(pins[relay],LOW);

  }  
  if(inputString.startsWith("H")){    
    int relay = inputString.substring(1,2).toInt();
    digitalWrite(pins[relay],HIGH);

  }

  if(inputString.startsWith("a")){    
    for(int i = 0;i<8;i++){
      if(inputString.substring(i+1,i+2) == "L"){
        digitalWrite(pins[i],HIGH);
      }else{
        digitalWrite(pins[i],LOW);
      }
    }
    

  }

}


void loop() {

  if (stringComplete) {    
    Serial.println("Recieved:"+inputString);

    execute(inputString);
     
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

  
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '=') {
      stringComplete = true;
    }
  }
}

