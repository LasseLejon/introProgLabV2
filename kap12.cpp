#include <iostream>
#include <cassert>
#include "vanligt.h"
using namespace std;
struct Exchangemoney{
    int numberOf500;
    int numberOf200;
    int numberOf100;
    int numberOf20;
    int numberOf10;
    int numberOf5;
    int numberOf1;
};

Exchangemoney exchangeMoneyFromQuantity(int a500, int a200, int a100, int a20,
                                        int a10, int a5, int a1){
    Exchangemoney fromQuantity;
    fromQuantity.numberOf500=a500;
    fromQuantity.numberOf200=a200;
    fromQuantity.numberOf100=a100;
    fromQuantity.numberOf20=a20;
    fromQuantity.numberOf10=a10;
    fromQuantity.numberOf5=a5;
    fromQuantity.numberOf1=a1;
    return fromQuantity;
}
Exchangemoney exchangeMoneyFromAmount(int amount){
    Exchangemoney fromAmount;
    fromAmount.numberOf500=amount/500;
    amount-=fromAmount.numberOf500*500;
    fromAmount.numberOf200=amount/200;
    amount-=fromAmount.numberOf200*200;
    fromAmount.numberOf100=amount/100;
    amount-=fromAmount.numberOf100*100;
    fromAmount.numberOf20=amount/20;
    amount-=fromAmount.numberOf20*20;
    fromAmount.numberOf10=amount/10;
    amount-=fromAmount.numberOf10*10;
    fromAmount.numberOf5=amount/5;
    amount-=fromAmount.numberOf5*5;
    fromAmount.numberOf1=amount;
    return fromAmount;

}
int amountFromExchangemoney(Exchangemoney exchangemoney){
    int amount2=0;
    amount2+=exchangemoney.numberOf500*500;
    amount2+=exchangemoney.numberOf200*200;
    amount2+=exchangemoney.numberOf100*100;
    amount2+=exchangemoney.numberOf20*20;
    amount2+=exchangemoney.numberOf10*10;
    amount2+=exchangemoney.numberOf5*5;
    amount2+=exchangemoney.numberOf1*1;
    return amount2;
}
void printExchangeMoney(Exchangemoney ex){
    cout << ex.numberOf500 << ex.numberOf200 << ex.numberOf100 << ex.numberOf20 << ex.numberOf10 << ex.numberOf5 << ex.numberOf1;

}
void autoTestExchangeMoney(){
    Exchangemoney vp=exchangeMoneyFromAmount(836);
    assert(amountFromExchangemoney(vp)==836);
    printExchangeMoney(exchangeMoneyFromQuantity(1,2,3,4,5,6,7));



}

void shortcutToKap12(){
    autoTestExchangeMoney();
}
