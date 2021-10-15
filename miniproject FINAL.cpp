#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<string.h>
#include<iomanip>

using namespace std;


    class members {
        protected:
       
        string name[5];
        int age [5];
        int mem_id[5];
        int m_num[5];
        char gender [5];
        int i;
        
        public:
        	
	void add_mem()
	{
		
        cout<<"your member i_d is "<<"\t"<<mem_id[i]<<"\t"<<":)"<<endl;
        cout<<"Enter your name :";cin>>name[i];
        cout<<"Enter you age:";cin>>age[i];
        cout<<"your gender(m/f)? ";cin>>gender[i];
        
          
        fstream fout("GYM.txt");                                                                                                                                                                                                                           fout.open("Gym.txt");
        fout<<mem_id[i]<<"\n";
        fout<<name[i]<<"\n";
         fout<<age[i]<<"\n";
         fout<<gender[i]<<"\n";
        fout<<"---------------------------------";
        fout.close();
      	i++;
        }
    
        
       
        
    };
 class excercise :  public virtual members 
 {
   public:
    int num ;
    void workout_fem();

};

void excercise::workout_fem()
{
     enum {monday=1,tuesday=2,wednesday=3,thurday=4,friday=5,saturday=6,sunday=7};
   cout<<"workout as per day of the week will be displayed:"<<endl
        <<" 1=monday, 2=tuesday,3=wednesday,4=thurday ,5=friday, 6=saturday ,7=sunday"<<endl
    << "Enter NO:\n"<<endl;
    cin>>num;
        switch(num){
            case 1:
                cout<<"\nFull Body Workout :\t(40sec rets))\n 1.SQUAT PRESS\n2.LATERAL RAISE\n3.LUNGE CURL\n4.ROW TO EXTENSIONn5.LATERAL LUNGES\n6,LATERAL TAP\n7.PUSH UP ROW\n8.PLANK DRAG\n";                        
                   break;              
            case 2:
                cout<<"Booty and Hip Dips workout:\t(40sec rest)\n1.RUSSIAN TWIST CHOP\n2.BICYCLE CRUNCH\n3.CORKSCREW\n4.ALT TOE TOUCH\n5.SIDE PLANK CRUNCH\n";
                break;
            case 3:
              cout<<"Intense Abb workout:\t(15sec rest)\n1.TUCK V-UP\n2.HIP RAISE TWIST\n3.PLANK SCORPION\n4.BODY CLIMBER\n5.LEG DROP TOE TAP\n6.ROLL UP CLAP\n7.PLANK HOP AND JACKS\n8.PLANK LEG RAISE AND TUCK\n";
              break;
            case 4:
                cout<<"Back and Arms workout:\t(90-120sec rest)\n1.CHEST PRESS\n2.CHEST FLY\n3.BENT OVER ROW\n4.BICEP CURL\n5.SHOULDER PRESS\n6.LATERAL RAISE (REPEAT)\n";
                break;
            case 5:
                 cout<<"Fat Burn workout:\t(5-20sec rest)\n1.BUTT KICKERS\n2.JUMPING JACKS\n3.INCHWORM\n4.FASTFOOT\n5.SHUFFLE TOUCH GROUND\n6.PUSH UP SHOULDER TAP\n7.LUNGE ANS SKIP\n8.SHUFFLE BURPEES\n";
                 break;
               
            case 6:
                  cout<<"Thigh and Leg workout:\t(\n";
                  break;
                
            case 7:
   cout<<"HOLIDAY REST WELL :):>\n";
   break;
   
    }
}

class attendance :virtual public members
{
	public:
  
 int m;
    void mark_attendance(){
    	cout<<"Enter mem_id:\n";
    	cin>>m;
    	for (int j=0;j<5;j++){
    		if(m==mem_id[j])
    		{
    			m_num[j]=m_num[j]+1;
    			break;
			}
		}
    
    }
};


class payment: public attendance ,public excercise
{
	public:
	int flag[5];
    int mpay;
  	
  	payment()
  	{
  		i=0;
  		for(int j=0;j<5;j++)
  		{
  			flag[j]=0;	
		}
		for(int j=0;j<5;j++)
		{
			mem_id[j]=j*10+10;
		}
		for(int j=0;j<5;j++)
		{
			m_num[j]=0;
		}
	}
  	
    void calc()
	{
    	mpay=700;
    	
    	cout<<"Enter your mem_id to PAY:-";
    	cin>>m;
    	for(int j=0;j<5;j++)
    	{
    		if(m==mem_id[j])
    		{
    			cout<<"PAY:$"<<setw(10)<<showpoint<<m_num[j]*mpay<<endl<<endl;
    			flag[j]=1;
    			cout<<"Thank you:)";
    			break;
			}
		}
	}
	

    void monthly_pay()
	{
        cin>>m;
        
        for(int j=0;j<5;j++)
        {
        	if(m==mem_id[j])
    		{
    			if (flag[j]==1)
	       			cout<<"PAYMENT DONE.\n";
	       		
	       		else
	       		{
					cout<<"PAYMENT NOT DONE\n";
	       			calc();
				}
				break;
			}
		}
		
    }
   
};

int main()
{
    int choice;
   
    payment E;
    
   
    while(1)
	{
		cout<<setw(10)<<"1.ADD member:-\n"<<left<<"2.WEEK WORKOUTS:-\n"<<"3.mark WEELY ATTENDANCE:-\n"<<"4.TO PAY (week/s):-\n"<<"5.check PENDING PAYMENT\n"<<"6.TO EXIT\n";
	    cout<<"ENTER YOUR CHOICE:__";
	    cin>>choice;
	    cout<<endl<<endl;
    
	    switch(choice)
		{
	        case 1:
	         
	            cout<<"Enter details for member";
	            E.add_mem();
	            
	            cout<<"Member added SUCCESSFULLY :):)"<<endl;
	            cout<<"--------------------**-------------------------\n";
	            break;
	        case 2:
	        	cout<<"To Know About excercises PRESS NO.Accordingly :)(:\n\n";
	            E.workout_fem();
	            cout<<"--------------------**-------------------------\n";
	            break;
	        
	        case 3:
	            E.mark_attendance();
	            cout<<"WEEKLY ATTENDANCE MARKED \n"
	            <<"WELCOME BEGIN WITH YOUR WORKOUT:))";
	            cout<<"--------------------**-------------------------\n";
	            break;
	        case 4:
	            	E.calc() ;
	            	cout<<"--------------------**-------------------------\n";
	            	break;
	        case 5:
	            		cout<<"Enter you mem_id to check if you payed :-";
	            		E.monthly_pay();
	            		cout<<"--------------------**-------------------------\n";
	            		break;
	        case 6:
	            cout<<"THANK YOU!! :>";
	            exit(0);       
	    }
	
	}			
    getch();
}
    
    
