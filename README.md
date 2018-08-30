
Topic - to develop a program to find nearest city

>> About Project:
	-> The program offers 2 choices to specify user's location 
		a) Entering city name (e.g. jaipur) - type '1'
			On entering, if the name matches to any city in the database, then it is accepted.
		b) Entering user's co-ordinates (e.g. latitude - 57.43) - type'2'
			on entering, if the co-ordinates are in the indian region then it is accepted.
	-> After entering the location, usr is asked for the no. of closest cities he/she wants to see from the current location.
	-> The top n closest cities are shown and the user can choose between them for more information.
>> Features;
	-> Multiple ways to enter location
	-> Spell checker for city name upto 1 character
	-> Error handling at every input
	-> Multiple units in which output is shown
	-> Database of 1000 cities
	-> Information like state and local language of cities
>> Instructions;
	->make sure that the program file(main.c) and the database(p21.txt) are in the same directory.
	->Open the terminal by pressing crtl+alt+t
	->compile the program by typing 'gcc -o main main.c -lm'
	-> run the program by typing './main'
	-> enter 1 or 2 as desired to specify your location
	-> if 1 is entered, enter your city name.
		-> if you entered wrong spelling of the city upto 1 character, choose the correct one from the options provided.
		-> then enter the no. of closest cities you want to know.
		-> choose any of the cities shown to see additional info.
	-> if 2 is  entered, enter the latitude and longitude of your location upto 2 decimal places.
		-> then enter the no. of closest cities you want to know.
		-> choose any of the cities shown to see additional info.
*thank you*
			
