int lstat = 0;
void setup() 
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
void forward()
{
  Serial.println("Forward");
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
void backward()
{
  Serial.println("Backward");
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
void left()
{
  Serial.println("Left");
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}
void right()
{
  Serial.println("Right");
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}
void loop() 
{
  if(Serial.available())
  {
    switch(Serial.read())
    {
      case 'w':
        forward();
        break;
      case 's':
        backward();
        break;
      case 'a':
        left();
        break;
      case 'd':
        right();
        break;
      case 'q':
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        break;
      case 'o':
        if(lstat == 0)
        {
          digitalWrite(7, HIGH);
          lstat = 1;
        }
        else if(lstat == 1)
        {
          digitalWrite(7, LOW);
          lstat = 0;
        }
        break;
    }
  }  
}
