#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class Shopping{
        private:
            int product_code;
            float discount,price,product_price;
            string product_name;
        public:
            void menu();
            void administator();
            void buyer();
            void add();
            void edit();
            void re_move();
            void p_list();
            void recipe();
};
void Shopping :: menu(){
    int choise;
    string email,password;

    m:
     cout<<" \t\t\t\t\t_________                                     _______   \n";
    cout<<" \t\t\t\t\t_________   Welcome to menu   _______   \n";
    cout<<" \t\t\t\t\t_________                                      _______   \n";

    cout<<" \t\t\t\t\t_________   Your option  _______   \n\n\n";

     cout<<" \t\t\t\t\t_________  1)Administrator  _______   \n";
     cout<<" \t\t\t\t\t_________  2)Buyer       _______   \n";
     cout<<" \t\t\t\t\t_________  3)Exit       _______  __ \n";
     cout<<" \t\t\t\t  _______ Enter your option _____\n";
     cin>>choise;

    switch(choise){
            case 1:
                cout<<"______Please login ____\n";
                cout<<"______Enter email _____\n";
                cin>>email;
                cout<<"______Enter password_____\n";
                cin>>password;
                if(email=="udzzal@gmail.com"&&password=="123456"){
                    administator();
                }else{
                cout<<"\t\t\t\t Invalid email or password ___\n";
                }
                break;
            case 2:
                buyer();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"______Plese enter the correct option___\n";
    }
goto m;
};

void Shopping ::administator(){

int choise;
    m:
     cout<<" \t\t\t\t\t_________                                     _______   \n";
    cout<<" \t\t\t\t\t_________   Welcome to administrator menu   _______   \n";
    cout<<" \t\t\t\t\t_________                                      _______   \n";

    cout<<" \t\t\t\t\t_________   Your option  _______   \n\n\n";

     cout<<" \t\t\t\t\t_________  1)Add  product _______   \n";
     cout<<" \t\t\t\t\t_________                                      _______   \n";
     cout<<" \t\t\t\t\t_________  2) Modify   product  _______   \n";
     cout<<" \t\t\t\t\t_________                                      _______   \n";
     cout<<" \t\t\t\t\t_________ 3 )Delete   product   _______  __ \n";
     cout<<" \t\t\t\t\t_________                                      _______   \n";
     cout<<" \t\t\t\t\t_________ 4 )Back to menu  _______  __ \n";

     cout<<" \t\t\t\t  _______ Enter your option _____\n";
     cin>>choise;

    switch(choise){
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                re_move();
                break;
            case 4:
                menu();
            default:
                cout<<"______Plese enter the correct option___\n";
    }
goto m;
};

void Shopping ::buyer(){
    m:
    int choise;
    cout<<"\t\t\t\t______Buyer menu______\n";
    cout<<"\t\t\t\t_______                  _______\n";
    cout<<"\t\t\t\t____________1. Buy product _______\n";
    cout<<"\t\t\t\t____________               _______\n";
    cout<<"\t\t\t\t____________2 back to menu _______\n";
    cout<<"\t\t\t\t_______                  _______\n";
    cout<<"\t\t\t_____Enter choise_________\n";
    cin>>choise;

    switch(choise){
        case 1:
                recipe();
                break;
            case 2:
                menu();
                break;
            default:
                cout<<"______Plese enter the correct option___\n";
    }
goto m;
};

void Shopping::add(){
            m:
            fstream data;
            int c,token=0;
            float p,d;
            string n;

            cout<<"\t\t\t\t_____Add product________\n"<<endl;
            cout<<"\t\t\t\t                                                    \n";

            cout<<"\t\t\t\t____please enter product code which need to add_____\n";
            cin>>product_code;
            cout<<"\t\t\t\t______please enter product name____\n";
            cin>>product_name;
            cout<<"\t\t\t\t______please enter product price____\n";
            cin>>product_price;
            cout<<"\t\t\t\t______please enter product discount ____\n";
            cin>>discount;

        //file handaling operation start here for add function
        data.open("shop_product.txt",ios::in);
        if(!data){
            data.open("shop_product.txt", ios::app | ios::out);
            data<<"  "<<product_code<<"  "<<product_name<<"  "<<product_price<<"  "<<discount<<"\n";
            data.close();
        }else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c==product_code){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if(token ==1){
            goto m;
        }else{
        data.open("shop_product.txt", ios::app | ios::out);
            data<<"  "<<product_code<<"  "<<product_name<<"  "<<product_price<<"  "<<discount<<"\n";
            data.close();
        }
    }
    cout<<"\t\t\t\t\t_____record inserted ______\n";
}
void Shopping ::edit(){
        fstream data,data1;
        int pkey,token=0,c;
        float p,d;
        string n;
        cout<<"\n\t\t\t\t Modify the record \n";
        cout<<"\n \t\t\t\t\t   product code plese   :";
        cin>>pkey;

        data.open("shop_product.txt",ios::in);
        if(!data){
            cout<<"\n\n\n file doesnt exist ";
        }else{
        data1.open("database1.txt",ios::app | ios::out);
    data >> product_code >> product_name >> product_price >> discount;
        while(!data.eof()){
                //while start here
            if(pkey==product_code){
                cout<<"\n\t\t\t\t\t____ product new code ____ :";
                cin>>c;
                cout<<"\n\t\t\t\t\t____ new product name ____ :";
                cin>>n;
                cout<<"\n\t\t\t\t\t____ product new price ____ :";
                cin>>p;
                cout<<"\n\t\t\t\t\t____ product new discount for product  ____ :";
                cin>>d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";

                cout<<"\n\t\t\t    record inserted  \n";
                token++;

            }else{
            data1<<"  "<<product_code<<"  "<<product_name<<"  "<<product_price<<"  "<<discount<<"\n";
            }
             data>>product_code>>product_name>>product_price>>discount;
            //while ends here
        }
        data.close();
        data1.close();

        remove("shop_product.txt");
        rename("database1.txt","shop_product.txt");
        if(token==0){
            cout<<"\n\t\t\t _____record not found   sorry ! ___\n";
        }

        }
}
void Shopping:: re_move(){
    fstream data,data1;
    int pkey,token=0;
    cout<<"\n\t\t\t\t_____  Delete product_____\n";
    cout<<"\t\t\t\t_____enter product code which one to delete___\n";
    cin>>pkey;

    data.open("shop_product.txt",ios::in);
    if(!data){
        cout<<"file does not exist \n";
    }else
    {
        data1.open("database1.txt",ios::app| ios::out);
        data>>product_code>>product_name>>product_price>>discount;
        while(!data.eof()){
            if(product_code==pkey){
                cout<<"\t\t\t ____ product deleted successfully";
                token++;
            }else{

            data1<<product_code<<product_name<<product_price<<discount<<"\n";

            }
            data>>product_code>>product_name>>product_price>>discount;

            //while ends here
        }
        data.close();
        data1.close();
        remove("shop_product.txt");
        rename("database1.txt","shop_product.txt");

        if(token==0){
            cout<<"\n\t\t\t  record not found ";
        }

    }
}

void Shopping::p_list(){
        fstream data;
        data.open("shop_product.txt",ios::in);
        cout<<"\n\t\t\t\t_________________________\n";
        cout<<"\n\t\t\t_productcode \t\t product name \t\t\t product price___\n";
        cout<<"\n\t\t\t\t_________________________\n";

        data>>product_code>>product_name>>product_price>>discount;

        while(!data.eof()){
            cout<<product_code<<"\t\t"<<product_name<<"\t\t"<<product_price<<"\n";
            data>>product_code>>product_name>>product_price>>discount;

        }
        data.close();
}

void Shopping::recipe(){

    fstream data;
    int p_code[100],p_quntity[100];
    int  c=0;
    float discount=0,total=0,amount=0;
    string choise;
    cout<<"\n\n\t\t\t\t_____RECEPT____   ";
    data.open("shop_product.txt",ios::in);
    if(!data){
        cout<<"\n\n\n Empty database \n\t\t\t  Plese ask the administrator to insert product in database\n";
        cout << "\t\t\tPlease ask the administrator to insert products into the database.\n";
        return;
    }else{
        data.close();
        p_list();
        cout<<"\n\t\t\t\t_________________________\n";
        cout<<"\n\t\t\t\t                                                       \n";
        cout<<"\n\t\t\t\t__Please enter the order _____\n";
        cout<<"\n\t\t\t\t                                                        \n";
        cout<<"\n\t\t\t\t___________________________\n";
        do{
            cout<<"\n  enter product code  \n";
            cin>>p_code[c];
            cout<<"\n  enter product quantity  \n";
            cin>>p_quntity[c];

            bool duplicate=false;
            for(int i=0;i<c;i++){
                if(p_code[c]==p_code[i]){
                    cout<<"\n\t\t\t\t___Duplicate code \n";
                    duplicate=true;
                    break;
                        }
                    }
            if(!duplicate){
                    c++;}

            cout<<"you want to buy another product ? if  yes please press Y else N ";
            cin>>choise;
        }
        while(choise=="Y");
            cout<<"__________Recept________\n";
            cout<<"product no \t product name \t product quantity\t price\t\tamount\t amount with discount  \n";

            for(int i=0;i<c;i++){
                data.open("shop_product.txt",ios::in);
                data>>product_code>>product_name>>product_price>>discount;
                while(!data.eof()){
                    if (product_code==p_code[i]){
                        amount=product_price*p_quntity[i];
                        discount=amount-(amount*discount/100);
                        total=total+discount;
                        cout<<" \n\t"<<product_code<<"\t\t"<<product_name<<"\t\t"<<p_quntity[i]<<"\t\t"<<product_price<<"\t\t"<<amount<<"\t\t"<<discount;

                    }
                    data>>product_code>>product_name>>product_price>>discount;
                }

            data.close();
        }
        cout<<"\n\n\t\t_________________________\n";
        cout<<"\n\n\t\t_________________________\n";
        cout<<" \t\t_____   Total amount :: "<<total<<endl;
        cout<<"\n\n\t\t_________________________\n";
}
}
int main(){

    Shopping z;
    z.menu();

getch();
return 0;

}



