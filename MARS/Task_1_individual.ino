/*
 * Author: Md Asifur Rahman Saikot
 * Iteration: 1
 * Date: 08-10-2025
 * Description: Task-1 implemented with loops and a look-up table.
 * Notes: Tested on Generic Arduino-Compatible Board. LEDs connected to pins 4,3,2.
 */
int pins[]={4, 3, 2};

void setup() 
{
  for (int i =0; i<3;i++)
  {
    pinMode(pins[i], OUTPUT);
  }

}
int step[][3]=
{
  {HIGH, LOW, LOW},
  {HIGH, HIGH, LOW},
  {LOW, LOW, HIGH},
  {LOW, HIGH, LOW}
};
int delays[4]={3000,1500,3000,1500};

void loop() 
{
  for(int s=0; s<4; s++)
  {
    for (int x=0; x<4; x++)
    {
      digitalWrite(pins[x],step[s][x]);
    }
    delay(delays[s]);
  }

}
