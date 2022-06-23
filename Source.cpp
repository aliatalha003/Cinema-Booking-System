#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define timenow 15 

void check_time(int firsttime, int secondtime);
void check_reservationComplete(int checkvar, int secondtime);
void creditcard(int ticketsnum, int thatreid);
void capacity(int movienum, int screenT, int capa, int reser, int ticketsnum);
void checkcapacity(int ticketsnum, int movienum, int selectime);
void showmovie();

int x, ticketsnum, movienum;

using namespace std;
struct theatre {
	string theatre_id;
	int capacity;
	int reserved;
};
struct TIME {
	string hour;
	theatre th;
};
struct SI {
	string theatre[2];
	TIME screen_time[4];
};
struct mov {
	string title;
	string director;
	string actor[2];
	string rating;
	SI screeninfo;
}movie[4];

void showmovie()
{
	int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0;
	ifstream file;

	file.open("movie1.txt");
	if (file.fail())
	{
		cout << "error.\n";
	}
	else
	{
		string line;

		getline(file, line);
		movie[0].title = line;
		getline(file, line);
		movie[0].director = line;
		getline(file, line);
		movie[0].actor[0] = line;
		getline(file, line);
		movie[0].actor[1] = line;
		getline(file, line);
		movie[0].rating = line;
		getline(file, line);
		movie[0].screeninfo.theatre[0] = line;
		getline(file, line);
		movie[0].screeninfo.screen_time[0].hour = line;
		getline(file, line);
		movie[0].screeninfo.screen_time[1].hour = line;


		getline(file, line);
		movie[1].title = line;
		getline(file, line);
		movie[1].director = line;
		getline(file, line);
		movie[1].actor[0] = line;
		getline(file, line);
		movie[1].actor[1] = line;
		getline(file, line);
		movie[1].rating = line;
		getline(file, line);
		movie[1].screeninfo.theatre[0] = line;
		getline(file, line);
		movie[1].screeninfo.screen_time[2].hour = line;
		getline(file, line);
		movie[1].screeninfo.screen_time[3].hour = line;


		getline(file, line);
		movie[2].title = line;
		getline(file, line);
		movie[2].director = line;
		getline(file, line);
		movie[2].actor[0] = line;
		getline(file, line);
		movie[2].actor[1] = line;
		getline(file, line);
		movie[2].rating = line;
		getline(file, line);
		movie[2].screeninfo.theatre[1] = line;
		getline(file, line);
		movie[2].screeninfo.screen_time[0].hour = line;
		getline(file, line);
		movie[2].screeninfo.screen_time[1].hour = line;

		getline(file, line);
		movie[3].title = line;
		getline(file, line);
		movie[3].director = line;
		getline(file, line);
		movie[3].actor[0] = line;
		getline(file, line);
		movie[3].actor[1] = line;
		getline(file, line);
		movie[3].rating = line;
		getline(file, line);
		movie[3].screeninfo.theatre[1] = line;
		getline(file, line);
		movie[3].screeninfo.screen_time[2].hour = line;
		getline(file, line);
		movie[3].screeninfo.screen_time[3].hour = line;
		file.close();
	}
	cout << movie[0].title << endl << "Director: " << movie[0].director << endl << "Actor1: " << movie[0].actor[0] << endl << "Actor2: " << movie[0].actor[1] << endl << "Rating: " << movie[0].rating << endl << "Theatre ID: " << movie[0].screeninfo.theatre[0]
		<< endl << "Screening time1: " << movie[0].screeninfo.screen_time[0].hour << endl << "Screening time2: " << movie[0].screeninfo.screen_time[1].hour << endl << endl;
	cout << movie[1].title << endl << "Director: " << movie[1].director << endl << "Actor1: " << movie[1].actor[0] << endl << "Actor2: " << movie[1].actor[1] << endl << "Rating: " << movie[1].rating << endl << "Theatre ID: " << movie[1].screeninfo.theatre[0]
		<< endl << "Screening time1: " << movie[1].screeninfo.screen_time[2].hour << endl << "Screening time2: " << movie[1].screeninfo.screen_time[3].hour << endl << endl;
	cout << movie[2].title << endl << "Director: " << movie[2].director << endl << "Actor1: " << movie[2].actor[0] << endl << "Actor2: " << movie[2].actor[1] << endl << "Rating: " << movie[2].rating << endl << "Theatre ID: " << movie[2].screeninfo.theatre[1]
		<< endl << "Screening time1: " << movie[2].screeninfo.screen_time[0].hour << endl << "Screening time2: " << movie[0].screeninfo.screen_time[1].hour << endl << endl;
	cout << movie[3].title << endl << "Director: " << movie[3].director << endl << "Actor1: " << movie[3].actor[0] << endl << "Actor2: " << movie[3].actor[1] << endl << "Rating: " << movie[3].rating << endl << "Theatre ID: " << movie[3].screeninfo.theatre[1]
		<< endl << "Screening time1: " << movie[3].screeninfo.screen_time[2].hour << endl << "Screening time2: " << movie[3].screeninfo.screen_time[3].hour << endl;

	a = stoi(movie[0].screeninfo.screen_time[0].hour);
	b = stoi(movie[0].screeninfo.screen_time[1].hour);
	c = stoi(movie[1].screeninfo.screen_time[2].hour);
	d = stoi(movie[1].screeninfo.screen_time[3].hour);
	e = stoi(movie[2].screeninfo.screen_time[0].hour);
	f = stoi(movie[2].screeninfo.screen_time[1].hour);
	g = stoi(movie[3].screeninfo.screen_time[2].hour);
	h = stoi(movie[3].screeninfo.screen_time[3].hour);

	cout << "\n===============================\n";

	cout << "Please , enter the movie number:";
	cin >> movienum;

	cout << " \nPlease , enter number of tickets:";
	cin >> ticketsnum;

	cout << "\n================================\n ";

	if (movienum == 1)
		check_time(a, b);    //Calling Time Function

	if (movienum == 2)
		check_time(c, d);

	if (movienum == 3)
		check_time(e, f);

	if (movienum == 4)
		check_time(g, h);

}

void check_time(int firsttime, int secondtime)
{
	if (timenow < firsttime)
	{
		checkcapacity(ticketsnum, movienum, firsttime);
		//Calling Capcity Function
	}
	else {
		if (timenow < secondtime)
		{
			cout << "we suggest you the second screening time for the movie at : " << secondtime << "\n \n • press 1 if you agree to complete your reservation : \n";
			cout << "\n \n • press 2 to cancel the reservation: \n ";
			cin >> x;
			//Calling Check Completing Reservation Function   
			check_reservationComplete(x, secondtime);
		}
		else {
			//Calling Exit Function 
			cout << "Reservation cancelled";
		}
	}
}
//Check Function  for Completing the Reservation
void check_reservationComplete(int checkvar, int secondtime)
{
	if (checkvar == 1)
	{
		//Calling Capacity Function
		checkcapacity(ticketsnum, movienum, secondtime);

	}
	else {
		cout << "Reservation cancelled\n";
	}
}

void checkcapacity(int ticketsnum, int movienum, int selectime)
{
	if (movienum == 1)
	{
		if (selectime == 14)
			capacity(1, 1, 50, 0, ticketsnum);

		else if (selectime == 18)
			capacity(1, 2, 50, 40, ticketsnum);
	}
	if (movienum == 2)
	{

		if (selectime == 16)
			capacity(2, 3, 50, 45, ticketsnum);

		else if (selectime == 20)
			capacity(2, 4, 50, 20, ticketsnum);
	}
	if (movienum == 3)
	{
		if (selectime == 16)
			capacity(3, 1, 50, 0, ticketsnum);
		else if (selectime == 18)
			capacity(3, 2, 50, 45, ticketsnum);

	}
	if (movienum == 4)
	{
		if (selectime == 14)
		{
			movie[3].screeninfo.screen_time[2].th.capacity = 50;
			movie[3].screeninfo.screen_time[2].th.reserved = 50;
			cout << "No seats available";
		}
		else if (selectime == 20)
			capacity(4, 4, 50, 20, ticketsnum);

	}
}
void capacity(int movienum, int screenT, int capa, int reser, int ticketsnum)
{
	int AS, a;
	movie[movienum - 1].screeninfo.screen_time[screenT - 1].th.capacity = capa;
	movie[movienum - 1].screeninfo.screen_time[screenT - 1].th.reserved = reser;
	AS = movie[movienum - 1].screeninfo.screen_time[screenT - 1].th.capacity - movie[movienum - 1].screeninfo.screen_time[screenT - 1].th.reserved;
	if (ticketsnum <= AS)
		creditcard(ticketsnum, movienum);
	else
	{
		cout << "there are " << AS << " available seats press 1 to book them or press 2 to cancel reservation\n";
		cin >> a;
		if (a == 1)
			creditcard(AS, movienum);
		else
			cout << "cancel";
	}
}
void creditcard(int ticketsnum, int theatreid)
{
	char arr[17];
	string TH;
	int cvv, total, otp;
	string name;
	if (theatreid == 1 || theatreid == 2)
		TH = movie[0].screeninfo.theatre[0];
	if (theatreid == 3 || theatreid == 4)
		TH = movie[3].screeninfo.theatre[1];

	cout << "Enter Cardholder Name." << endl;
	cin >> name;
	cout << "Hello! " << name << "," << " You are booking " << ticketsnum << " tickets with us.\n";
	cout << "Price per ticket is 80 EGP" << endl;
	total = ticketsnum * 80;
	cout << "Your total cost is " << total << "." << endl;

	cout << "Please Enter Your Credit Card Number(16 digits)" << endl;
	do {
		cin >> arr;
		if (strlen(arr) != 16)
		{
			cout << "please re-enter your card number\n";
			continue;
		}
		if (arr[0] == '4')
		{
			cout << "\nValid Visa Card" << endl;
			cout << "Please enter CVV" << endl;
			cin >> cvv;
			cout << "Please enter your OTP" << endl;
			cin >> otp;
			cout << "*******************************\n";
			cout << total << " EGP is withdrawn from your balance. Your tickets are ready under the name " << name << ".\n";
			cout << TH << endl;
			cout << "Please make sure you arrive on time.\nFees do not include 3D glasses.\nThank you for choosing us!\n";
			cout << "*******************************\n";
			break;
		}
		else if (arr[0] == '5')
		{
			cout << "\nValid MasterCard" << endl;
			cout << "Please enter CVV" << endl;
			cin >> cvv;
			cout << "Please enter your OTP" << endl;
			cin >> otp;
			cout << "*******************************\n";
			cout << total << " EGP is withdrawn from your balance. Your tickets are ready under the name " << name << ".\n";
			cout << TH << endl;
			cout << "Please make sure you arrive on time.\nFees do not include 3D glasses. \nThank you for choosing us!\n";
			cout << "*******************************\n";
			break;
		}
		else if (arr[0] == '3' && arr[1] == '7')
		{
			cout << "\nValid American Express Card" << endl;
			cout << "Please enter CVV" << endl;
			cin >> cvv;
			cout << "Please enter your OTP" << endl;
			cin >> otp;
			cout << "*******************************\n";
			cout << total << " EGP is withdrawn from your balance. Your tickets are ready under the name " << name << ".\n";
			cout << TH << endl;
			cout << "Please make sure you arrive on time.\nFees do not include 3D glasses. \nThank you for choosing us!\n";
			cout << "*******************************\n";
			break;
		}
		else
		{
			cout << "\nInvalid card Number. Please make sure you entered 16 digits for credit number and 3 digits for cvv.\n";
			continue;
		}
	} while (arr[0] != 4 && arr[0] != 5 && (arr[0] != 3 && arr[1] != 7));
}

int main()
{
	int ans;
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	cout << "                                                   CINEMA BOOKING SYSTEM                                              \n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	do
	{
		cout << "MAIN MENU:-\n";
		cout << "1. Book a ticket.\n\n2. Contact Us\n\n3. Exit\n";
		cin >> ans;
		switch (ans)
		{
		case 1:
			showmovie();
			break;
		case 2:
			cout << "-Email: ahm111@gmail.com\n-Social Media Info: Instagram:- ahm111.\n-Phone Number: 00201234567.\n";
			break;
		case 3:
			break;
		default:
			cout << "invalid choice , please choose another number\n";
			break;
		}
	} while (ans != 1 && ans != 2 && ans != 3);
	return 0;
}