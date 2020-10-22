#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
/*
 Creat a struct called menuItemTtpe to store a string variable and a integer variable
 */
struct menuItemType{
    public:
    string menuItem;
    double menuPrice;
};

/*
 Here are the prototype of my function
 
 @getData will receive a menuItemType array which represent menuList,
        an Integer variable as index,
        and another menuItemTpye variable.
 
 @showMenu will show our menu to the user
 
 @printCheck will calculate the tax, summary and print the check to the user
 */
void getData(menuItemType [],int ,menuItemType);
void showMenu(menuItemType[]);
void printCheck(double,string [],double [],int);

int main(){
    menuItemType menuList[8];
    /*
     Here I created 8 different breakfast which samillar with your instruction,
     and I pass these arguments to my getDara function to organize my menu.
     */
    menuItemType breakfastOne;
    breakfastOne.menuItem = "Plain Egg";
    breakfastOne.menuPrice = 1.45;
    getData(menuList,0,breakfastOne);
    
    menuItemType breakfastTwo;
    breakfastTwo.menuItem = "Bacon and Egg";
    breakfastTwo.menuPrice = 2.45;
    getData(menuList,1,breakfastTwo);

    menuItemType breakfastThree;
    breakfastThree.menuItem = "Muffin";
    breakfastThree.menuPrice = 0.99;
    getData(menuList,2,breakfastThree);

    menuItemType breakfastFour;
    breakfastFour.menuItem = "French Toast";
    breakfastFour.menuPrice = 1.99;
    getData(menuList,3,breakfastFour);

    menuItemType breakfastFive;
    breakfastFive.menuItem = "Fruit Basket";
    breakfastFive.menuPrice = 2.49;
    getData(menuList,4,breakfastFive);

    menuItemType breakfastSix;
    breakfastSix.menuItem = "Cereal";
    breakfastSix.menuPrice = 0.69;
    getData(menuList,5,breakfastSix);

    menuItemType breakfastSeven;
    breakfastSeven.menuItem = "Coffee";
    breakfastSeven.menuPrice = 0.50;
    getData(menuList,6,breakfastSeven);

    menuItemType breakfastEight;
    breakfastEight.menuItem = "Tea";
    breakfastEight.menuPrice = 0.75;
    getData(menuList,7,breakfastEight);
    
    /*
     I called showMenu here to show the menu to the user
     */
    showMenu(menuList);
    /*
     @choice will record the user's selection
     @summaryPrice will calculate the summary of price
     @Item[100] will record which kinds of food that user select
     @ItemPrice[100] will recode the price of food everytime
     @index will record how many food that the user orderd
     I think "Item[100]" and "ItemPrice[100]"can help me output the check easier
     */
    int choice;
    double summaryPrice = 0;
    string Item[100];
    double ItemPrice[100];
    
    int index = 0;
    /*
     This do-while loop will record the user's order until they input '0' to quit the program
     */
    do{
        cout<<"What do you want to eat today (0 to quit): ";
        cin>>choice;
        if(choice != 0){
            while(choice<0 || choice>8){
                cout<<"Your inupt should in range (0~8)! Please enter your choice again: ";
                cin>>choice;
            }
            summaryPrice += menuList[choice-1].menuPrice;
            Item[index] = menuList[choice-1].menuItem;
            ItemPrice[index] = menuList[choice-1].menuPrice;
            index++;
        }
    }while(choice!=0);
    /*
     If the user orderd nothing, the program will not call printCheck function
     */
    if(index>0){
        printCheck(summaryPrice,Item,ItemPrice,index);
    }
    else{
        cout<<"------------------------------------------------------";
        cout<<"\nWelcome to Jhonny's Restaurant"<<endl;
        cout<<"------------------------------------------------------\n";
    }
    return 0;
}
/*
 Here is the implementation of getData function
 */
void getData(menuItemType temp[],int index,menuItemType food){
    temp[index] = food;
}
/*
 Here is the implementation of showMenu function
 I don't know how to make sure different string can have the same blank sapce between
 ItemName and ItemPrice, so I use setw() to get the blank space.
*/
void showMenu(menuItemType menuList[]){
    cout<<"---------------Menu--------------"<<endl;
    cout<<menuList[0].menuItem<<setw(20)<<"$"<<fixed<<setprecision(2)
        <<menuList[0].menuPrice<<setw(5)<<"(1)"<<endl;
    cout<<menuList[1].menuItem<<setw(16)<<"$"<<fixed<<setprecision(2)
        <<menuList[1].menuPrice<<setw(5)<<"(2)"<<endl;
    cout<<menuList[2].menuItem<<setw(23)<<"$"<<fixed<<setprecision(2)
        <<menuList[2].menuPrice<<setw(5)<<"(3)"<<endl;
    cout<<menuList[3].menuItem<<setw(17)<<"$"<<fixed<<setprecision(2)
        <<menuList[3].menuPrice<<setw(5)<<"(4)"<<endl;
    cout<<menuList[4].menuItem<<setw(17)<<"$"<<fixed<<setprecision(2)
        <<menuList[4].menuPrice<<setw(5)<<"(5)"<<endl;
    cout<<menuList[5].menuItem<<setw(23)<<"$"<<fixed<<setprecision(2)
        <<menuList[5].menuPrice<<setw(5)<<"(6)"<<endl;
    cout<<menuList[6].menuItem<<setw(23)<<"$"<<fixed<<setprecision(2)
        <<menuList[6].menuPrice<<setw(5)<<"(7)"<<endl;
    cout<<menuList[7].menuItem<<setw(26)<<"$"<<fixed<<setprecision(2)
        <<menuList[7].menuPrice<<setw(5)<<"(8)"<<endl;
    cout<<endl;
    cout<<"------------------------------------------------------\n";
    cout<<"Enter the Number behind the price to order the food!"
        <<"\n(Use number '0' to quit this App!)"<<endl;
    cout<<"------------------------------------------------------\n";
}
/*
 Here is the implementation of showMenu function
 I choose the 'Bacon and Egg' as the longest string and record its length.
 If next output shorter than 'Bacon and Egg', my program will adjust the width
 to make sure the output have the same blank spack between ItemName and ItemPrice.
*/
void printCheck(double summary,string orderList[],double price[],int index){
    cout<<"------------------------------------------------------";
    cout<<"\nWelcome to Jhonny's Restaurant"<<endl;
    cout<<"------------------------------------------------------\n";
    
    
    for(int i=0;i<index;i++){
        int stringLength = 13;
        int width = 0;
        if(stringLength > orderList[i].length()){
            width = stringLength-orderList[i].length();
        }
        else if(stringLength < orderList[i].length()){
            width = stringLength - orderList[i].length();
        }
       
        cout<<orderList[i]<<setw(16+width)<<"$"
        <<fixed<<setprecision(2)<<price[i]<<endl;
    }
    cout<<"Tax"<<setw(26)<<"$"<<summary*0.05<<endl;
    cout<<"Amount Due"<<setw(19)<<"$"<<summary+summary*0.05<<endl;
}
