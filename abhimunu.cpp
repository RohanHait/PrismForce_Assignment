#include <bits/stdc++.h>
using namespace std;

const int MAX_CIRCLE = 11 ;

vector<int> enemyPower(MAX_CIRCLE); 
int power , rechargeTime, skipTime ;

bool Abhimuny_Can_Cross(int currentCircle , int currPower,
                                    int recharge, int skip){
    if(currentCircle >= MAX_CIRCLE) return 1 ;

    int currLevel = enemyPower[currentCircle] + (currentCircle ==3 ? enemyPower[2] /2: 0 ) + (currentCircle ==7 ? enemyPower[6] /2: 0 ) ; // As K3 and K7 enemy can regenerate  to the half of their power
    bool flag = 0 ;
    // option 1 : he have the sufficient power he can fight 
    if(currLevel <= currPower) {
        flag |= Abhimuny_Can_Cross(currentCircle+ 1 , currPower - currLevel , recharge , skip) ;
    }
    // option 2 : he can recharge himself and continue the fight
    if(!flag && recharge && currLevel <= power) {
        flag |= Abhimuny_Can_Cross(currentCircle+1 , power - currLevel , recharge -1 , skip) ;
    }
    // option 3 : skip the fight ;
    if(!flag && skip){
        flag |= Abhimuny_Can_Cross(currentCircle+1 , currPower , recharge, skip -1) ;
    }
    return flag ;
}

void solve(){
    // cout << "Enter The Enemy Power from K1 , K2, .... K12\n" ;
    for (int i = 0; i < MAX_CIRCLE; i++)
    {
        cin >> enemyPower[i];
        cout << enemyPower[i] << " " ;
    }
    // cout << "\nEnter The power of  Abhimanyu: ";
    cin >> power;
    // cout <<  "\nEnter The time of  Abhimanyu can recharge himself: " ;
    cin >> rechargeTime;
    // cout  << "\nEnter The time of  Abhimanyu can skip the circle: ";
    cin >> skipTime;
    if(Abhimuny_Can_Cross(0,power,rechargeTime,skipTime)){
        cout << "\n Abhimanyu can cross the chakravyuha\n\n\n";
    } 
    else {
        cout << "\n Abhimanyu can't cross the chakravyuha\n\n\n";
        
    }
}


signed main()
{
    freopen("input.txt", "r", stdin); // TEST INPUT
    freopen("output.txt", "w", stdout); 
    int tc ; cin >>tc ; // TEST SIZE
    while(tc--)solve() ;

    return 0;
}
