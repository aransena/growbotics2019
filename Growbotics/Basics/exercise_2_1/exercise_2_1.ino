// Aran Sena 2019


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String myName = "Aran";
  String tempName = myName;
  tempName.toLowerCase();
  for(int i = sizeof(myName) - 2; i >= 0; i--){
    if(tempName[i]=='a' || tempName[i]=='e' || tempName[i]=='i' || tempName[i]=='o' || tempName[i]=='u'){
      Serial.print(myName[i]);
    }
  }
  Serial.print("\n");
}

void loop() {
  // put your main code here, to run repeatedly:

}
