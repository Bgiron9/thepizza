
#include <iostream>

using namespace std;
// i left off on toppings !!!!!!!
void happy ();			// happy will be considered our greeting function
int printMenu ();		//outputs everything on the pizza parlor menu
void pizzaSize (int sizePar, double &totalCostPar, int &sizeLocation);	//reads the price of pizza based on size
string pizzaCrust ();		//outputs the type of pizza crust
string pizzaToppings ();	//outputs all the pizza toppings chose
void menuReceipt (int sizePar, string crustPar, string toppingsPar);
void reciept ();		//outputs the final price of the order
double finalCost;
string name;

int
main ()
{

  happy ();
  int sizeTotal = printMenu ();

  string crustType = pizzaCrust ();	//stores the string from pizzaCrust 
  // for pizzaCrust function so it won't be lost in space

  string toppingsTotal = pizzaToppings ();

  menuReceipt (sizeTotal, crustType, toppingsTotal);

  reciept ();


  return 0;
}

void
happy ()			//this function introduces the pizza parlor
{
  //using string because you can only input one letter for char.

  cout << "Hello! Welcome to Bryan's Pizza Parlor.\n";
  cout << "Enter your first name.\n";
  cin >> name;
}


int
printMenu ()			//this function stores the size and brings it back to the main function
{
  using namespace std;

  cout << "Pizza Size(inches)..........Cost\n";
  cout << "10.........................$10.99\n";
  cout << "12.........................$12.99\n";
  cout << "14.........................$14.99\n";
  cout << "16.........................$16.99\n";
  cout << "" << endl;

  int size;

  cout << "What size pizza would you like? ";
  cin >> size;
  pizzaSize (size, finalCost, size);	//this is the variables declared for the pizzaSize function


  return size;

}

void
pizzaSize (int sizePar, double &totalCostPar, int &sizeLocation)
{

  if (sizePar == 10)		//used if/else-if statements to find the Cost correlated to pizza size
    {
      cout << "10inch pizza\n";
      totalCostPar = 10.99;
    }
  else if (sizePar == 12)
    {
      cout << "12inch pizza\n";
      totalCostPar = 12.99;
    }
  else if (sizePar == 14)
    {
      cout << "14inch pizza\n";
      totalCostPar = 14.99;
    }
  else if (sizePar == 16)
    {
      cout << "16inch pizza\n";
      totalCostPar = 16.99;
    }
  else
    {
      cout << "Size unavaliable, you will get a 12-inch pizza\n";
      totalCostPar = 12.99;
      sizeLocation = 12;
    }


}

string
pizzaCrust ()
{

  char crust;
  string crustType;

  cout << "What type of crust do you want?\n";
  cout << "(H) HandTossed, (T) Thincrust, or (D) DeepDish (enter" <<
    endl;
  cout << "H, T, or D) : ";
  cin >> crust;

  switch (crust)
    {
    case 'H':
    case 'h':
      cout << "Handtossed crust" << endl;
      cout << "" << endl;
      crustType = "Hand-tossed crust";
      break;
    case 'T':
    case 't':
      cout << "Thincrust" << endl;
      cout << "" << endl;
      crustType = "Thin-crust";
      break;
    case 'D':
    case 'd':
      cout << "deep-dish" << endl;
      cout << "" << endl;
      crustType = "deep-dish";
      break;
    default:
      cout << "Crust unavaliable, you will get Hand-tossed " << endl;
      crustType = "Hand-tossed";
      break;

    }
  return crustType;		//returns the crustType into the main function
}

string
pizzaToppings ()
{
  string toppings;
  int i = 0;			// i is used as a counter to use as a multiplier for each topping added
  char answer;
  cout << "Which toppings would you like to add?\n";
  cout <<
    "Additional toppings are $1.25 each, choose from: Pepperoni, Sausage,\n";
  cout << "Onion, or Mushroom\n";


  cout << "Do you want Pepperoni? (Y/N): ";
  cin >> answer;
  if (answer == 'y' || answer == 'Y')
    {
      toppings = toppings + " Pepperoni";
      i++;
    }

  cout << "Do you want Sausage? (Y/N): ";
  cin >> answer;
  if (answer == 'y' || answer == 'Y')
    {
      toppings = toppings + " Sausage";
      i++;
    }

  cout << "Do you want Onion? (Y/N): ";
  cin >> answer;
  if (answer == 'y' || answer == 'Y')
    {
      toppings = toppings + " Onions";
      i++;
    }

  cout << "Do you want Mushroom? (Y/N): ";
  cin >> answer;
  if (answer == 'y' || answer == 'Y')
    {
      toppings = toppings + " Mushrooms";
      i++;
    }

  cout << "Cheese" << toppings << endl;
  cout << "" << endl;

  finalCost = finalCost + i * 1.25;

  return toppings;
}

void
menuReceipt (int sizePar, string crustPar, string toppingsPar)
{
  using namespace std;
  cout << "Your order is as follows: \n";
  cout << sizePar << "-inch pizza" << endl;
  cout << crustPar << endl;
  cout << "Cheese" << toppingsPar << endl;

}

void
reciept ()
{
  if (name == "Bryan" || name == "bryan" || name == "Thomas" || name == "thomas")	// this if statement is our extra credit part
    {
      cout.setf (ios::fixed);
      cout.setf (ios::showpoint);
      cout.precision (2);

      cout << "You qualify for $2.00 discount\n";

      finalCost = finalCost - 2;

      cout << "The cost of your oder is: $" << finalCost << endl;
      cout << "The tax is: " << finalCost * 0.0795 << endl;
      cout << "Your total with tax included is $" << finalCost +
	finalCost * .0795 << endl;
    }
  else
    {
      cout.setf (ios::fixed);
      cout.setf (ios::showpoint);
      cout.precision (2);

      cout << "The cost of your oder is: $" << finalCost << endl;
      cout << "The tax is: $" << finalCost * 0.0795 << endl;
      cout << "The total with tax included is $" << finalCost * .0795 +
	finalCost << endl;
    }

  cout << "Your pizza will be ready in 30 minutes.\n";
}
