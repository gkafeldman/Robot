/*
Robot
Traffic light control.

*/
int leftRed = 11;
int leftAmber = 12;
int leftGreen = 10;
int amberFilter = 5;
int greenArrow = 3;
int rightRed = 4;
int rightAmber = 9;
int rightGreen = 8;
int buttonPin = 6;

int longTime = 16000;
int shortTime = 2500;
int flashTime = 1200;

int buttonState;             // the current reading from the input pin
int lastButtonState;   // the previous reading from the input pin
int waitForLow;

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

int modeNormal = 1;
int modeJoburgLights = 2;

int state = 1;
int mode = modeNormal;
int delayTime;

void setup()
{       
        lastButtonState = LOW;  
        waitForLow = LOW;
        
        
	pinMode(leftRed, OUTPUT);     
	pinMode(leftAmber, OUTPUT); 
	pinMode(leftGreen, OUTPUT); 
	pinMode(amberFilter, OUTPUT); 
	pinMode(greenArrow, OUTPUT); 
	pinMode(rightRed, OUTPUT); 
	pinMode(rightAmber, OUTPUT); 
	pinMode(rightGreen, OUTPUT); 
	pinMode(buttonPin, INPUT);
}

void CheckPins()
{
	digitalWrite(leftRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(rightRed, LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);

	digitalWrite(leftRed, HIGH);
	wait(1000);
	digitalWrite(leftRed, LOW);
	digitalWrite(leftAmber,HIGH);
	wait(1000);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,HIGH);
	wait(1000);
	digitalWrite(leftGreen,LOW);
	digitalWrite(rightRed, HIGH);
	wait(1000);
	digitalWrite(rightRed, LOW);
	digitalWrite(rightAmber,HIGH);
	wait(1000);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,HIGH);
	wait(1000);
	digitalWrite(rightGreen,LOW);
	digitalWrite(amberFilter,HIGH);
	wait(1000);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,HIGH);
	wait(1000);
	digitalWrite(greenArrow,LOW);
}

void AllStop()
{
	digitalWrite(leftRed, HIGH);
	digitalWrite(rightRed, HIGH);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,LOW);
}

void AllOff()
{
	digitalWrite(leftRed, LOW);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,LOW);
}

void LeftGo()
{
	digitalWrite(leftRed, LOW);
	digitalWrite(rightRed, HIGH);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,HIGH);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,LOW);
}

void LeftAmber()
{
	digitalWrite(leftRed, LOW);
	digitalWrite(rightRed, HIGH);
	digitalWrite(leftAmber,HIGH);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,LOW);
}

void RightGo()
{
	digitalWrite(leftRed, HIGH);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,HIGH);
}  

void RightAmber()
{
	digitalWrite(leftRed, HIGH);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,HIGH);
	digitalWrite(rightGreen,LOW);
}

void RightFilterOff()
{
	digitalWrite(leftRed, HIGH);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,HIGH);
}

void RightFilterOn()
{
	digitalWrite(leftRed, HIGH);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,HIGH);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,HIGH);
}

void RightFilterStop()
{
	digitalWrite(leftRed, HIGH);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,HIGH);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,HIGH);
}

void flash()
{
    int checkMode = mode;

	for(int i = 0; i < 3; i++)
	{
		digitalWrite(leftRed, HIGH);
		digitalWrite(rightRed, HIGH);
		digitalWrite(leftAmber,HIGH);
		digitalWrite(leftGreen,HIGH);
		digitalWrite(amberFilter,HIGH);
		digitalWrite(greenArrow,HIGH);
		digitalWrite(rightAmber,HIGH);
		digitalWrite(rightGreen,HIGH);
		wait(200);
        if (mode != checkMode)
			break;
		digitalWrite(leftRed, LOW);
		digitalWrite(rightRed, LOW);
		digitalWrite(leftAmber,LOW);
		digitalWrite(leftGreen,LOW);
		digitalWrite(amberFilter,LOW);
		digitalWrite(greenArrow,LOW);
		digitalWrite(rightAmber,LOW);
		digitalWrite(rightGreen,LOW);
		wait(200);
        if (mode != checkMode)
			break;
	}
}

void circle()
{
	int checkMode = mode;

	digitalWrite(leftRed, HIGH);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,LOW);
	wait(200);
	digitalWrite(leftRed, LOW);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,HIGH);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,LOW);
    if (checkMode == mode)
		wait(200);
	digitalWrite(leftRed, LOW);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,HIGH);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,LOW);
    if (checkMode == mode)
		wait(200);
	digitalWrite(leftRed, LOW);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen, LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow, LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen, HIGH);
    if (checkMode == mode)
		wait(200);
	digitalWrite(leftRed, LOW);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,HIGH);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,LOW);
    if (checkMode == mode)
		wait(200);
	digitalWrite(leftRed, LOW);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,HIGH);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,LOW);
    if (checkMode == mode)
		wait(200);
	digitalWrite(leftRed, LOW);
	digitalWrite(rightRed, LOW);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,HIGH);
	digitalWrite(rightGreen,LOW);
    if (checkMode == mode)
		wait(200);
	digitalWrite(leftRed, LOW);
	digitalWrite(rightRed, HIGH);
	digitalWrite(leftAmber,LOW);
	digitalWrite(leftGreen,LOW);
	digitalWrite(amberFilter,LOW);
	digitalWrite(greenArrow,LOW);
	digitalWrite(rightAmber,LOW);
	digitalWrite(rightGreen,LOW);
    if (checkMode == mode)
		wait(200);
}

void wait(int waitTime)
{
	for(int i = 0; i < waitTime; i++)
	{
		delay(1);

		//// read the state of the switch into a local variable:
		int reading = digitalRead(buttonPin);

		// check to see if you just pressed the button 
		// (i.e. the input went from LOW to HIGH),  and you've waited 
		// long enough since the last press to ignore any noise:  

		// If the switch changed, due to noise or pressing:
		if (reading != lastButtonState)
                {
			// reset the debouncing timer
			lastDebounceTime = millis();
		} 

		if ((millis() - lastDebounceTime) > debounceDelay)
                {
			// whatever the reading is at, it's been there for longer
			// than the debounce delay, so take it as the actual current state:
			buttonState = reading;
		}
		
                lastButtonState = reading;
                        
		if ((buttonState == HIGH) && (waitForLow == LOW))
		{
  			waitForLow = HIGH;
			mode++;
                        if (mode > 3)
	        		mode = 1;
			break;
		}

                waitForLow = buttonState;
	}
}

void NormalOperation()
{
	int filterCount = 0;

	while(mode == 1)
	{                
		switch (state)
		{
		case 1:
			AllStop();
			state = 2;
			delayTime = shortTime;
			break;
		case 2:
			LeftGo();
			state = 3;
			delayTime = longTime;
			break;
		case 3:
			LeftAmber();
			state = 4;
			delayTime = shortTime;
			break;
		case 4:
			AllStop();
			state = 5;
			delayTime = shortTime;
			break;
		case 5:

			if (filterCount == 0)
				filterCount = 1;

			if (((filterCount & 1) == 1) && (filterCount < 10))
				RightFilterOn();   
			else if ((filterCount & 1) ==0)
				RightFilterOff();
			
			if ((filterCount >= 10) && (filterCount < 13))
				RightFilterStop();
			
			if (filterCount >= 13)
				RightGo();
			
			filterCount++;

			if (filterCount >= 25)
			{
				state = 6;
				filterCount = 0;
			}

			delayTime = flashTime;
			break;
		case 6:
			RightAmber();
			state = 1;
			delayTime = shortTime;
			break;
		}

		wait(delayTime);
	}
}

void JoburgLights()
{
	while(mode == 2)
	{
		delayTime = flashTime;
		switch (state)
		{
		case 1:
			AllStop();
			state = 2;
			break;
		case 2:
			AllOff();
			state = 1;
			break;
		}
		
		wait(delayTime);
	}
}

void Disco()
{
	while (mode == 3)
	{
		circle();
		flash();
		flash();
	}
}

void loop()
{
        state = 1;
	switch (mode)
	{
		case 1:
			NormalOperation();
			break;
		case 2:
			JoburgLights();
			break;
		case 3: Disco();
                        break;
	}
}

