/*
 * Author: Ye Htet Kyaw
 * Iteration: 1
 * Date: 09-10-2025
 * Description: T-intersection
 * Notes: Tested on Wokwi
 */

const unsigned int State_Change_Delay = 800;
const unsigned int Extra_Stop_Go_Delay = 2000;
const unsigned int Safty_Delay = 800;

//numbering states to use in switch case
enum State {
  Stop,
  Get_Ready,
  Go,
  Slow_Down
};

class TrafficLight{
  public:
    int red_pin, yellow_pin, green_pin;
    State current_state;

    void green(){
      digitalWrite(green_pin, HIGH);
      digitalWrite(yellow_pin, LOW);
      digitalWrite(red_pin, LOW);

    }
    void yellow(){
      digitalWrite(green_pin, LOW);
      digitalWrite(yellow_pin, HIGH);
      digitalWrite(red_pin, LOW);
    }
    void red(){
      digitalWrite(green_pin, LOW);
      digitalWrite(yellow_pin, LOW);
      digitalWrite(red_pin, HIGH);
    }
    
    void setupPins() {
      pinMode(green_pin, OUTPUT);
      pinMode(yellow_pin, OUTPUT);
      pinMode(red_pin, OUTPUT);
    }
    
    TrafficLight(int r, int y, int g){
      red_pin = r;
      yellow_pin = y;
      green_pin = g;
    }
};

//Constructor
TrafficLight t1(13,12,11);// Through road
TrafficLight t2(4,3,2); // Terminating road

void setup() {
  
  t1.setupPins();
  t2.setupPins();
  t1.current_state = Stop;
  t1.red();
  t2.yellow();

}

void loop() {

  delay(State_Change_Delay);

  switch (t1.current_state) {

    case Stop:
      delay(Safty_Delay);
      t2.green();
      delay(Extra_Stop_Go_Delay);
      t1.yellow();
      t2.yellow();
      t1.current_state = Get_Ready;
      break;

    case Get_Ready:
      t2.red();
      delay(Safty_Delay);
      t1.green();
      t1.current_state = Go;
      break;

    case Go:
        delay(Extra_Stop_Go_Delay);
        t1.yellow();
        t2.yellow();
        t1.current_state = Slow_Down;
      break;

    case Slow_Down:
        t1.red();
        delay(Safty_Delay);
        t2.green();
        t1.current_state = Stop;
      break;
      
    default:
        t1.yellow();
        t2.yellow();
      break;
  }
}