#include <iostream>
using myInt = int32_t;
const myInt maxValue = INT32_MAX;
const myInt minValue = INT32_MIN;
using myLong = int64_t;

using namespace std;

class Int {
    myInt val;
    bool ov;
    bool div_zero;
    myLong longVal;
    
public:
    Int(myInt x=0) : ov{false} , val{x}  {}
    Int(myLong value) : ov{false} 
    {
        if ((value >= minValue) && (value <=maxValue))
            val = value;
        else {
            val = 0;
            cout << "!!! Initial value is out of range, set to zero\n"; 
        }
                
    }  
    myInt value() {return val;}
    myLong long_val(){return longVal;}
    bool is_div_zero(){return div_zero;}
    bool overflow() {return ov;}
    
    Int operator + (Int const & B) {
        Int res;
        res.val = val + B.val;
        res.ov = ((val>0)&&(B.val>0)&&(res.val<0)) || 
             ((val<0)&&(B.val<0)&&(res.val>0));
        if(res.ov){
            res.longVal = val;
            res.longVal += B.val;
            res.val = 0;
        }
        
        return res;
    }
    Int operator - (Int const & B) {
        Int res;
        res.val = val - B.val;
        res.ov = ((val>0)&&(B.val<0)&&(res.val<0)) || 
             ((val<0)&&(B.val>0)&&(res.val>0));
        if(res.ov){
            res.longVal = val;
            res.longVal -= B.val;
            res.val = 0;
        }
        return res;
    }
    
    Int operator * (Int const & B) {
        Int res;
        if(B.val == 0){
            res.val = 0;
            res.ov = false;
            return res;
        } else {
            res.val = val * B.val;    
        }
        res.ov = ((val != res.val/B.val));
        if(res.ov){
            res.longVal = val;
            res.longVal *= B.val;
            res.val = 0;
        }
        return res;
    }
    
    Int operator / (Int const & B) {
        Int res;
        res.div_zero = ((B.val == 0));
        if (res.div_zero){
            res.val = 0;
            
        } else {
            res.val = val / B.val;
        }
        
        return res;
    }
        
    
};
int main()
{
    //Int A(init);
    Int A(-0x7FFFFFFF);
    Int B(2);   
    Int C = A + B;
    Int D = A - B;
    Int E = A * B;
    Int F = A / B;
    
    cout<<"Hello World!" << endl;
    cout << '\n';
    cout<<"A = " <<A.value() << endl; //-0x7FFFFFFF
    cout<<"B = " <<B.value() << endl;
    cout << '\n';
    if(C.overflow()){
        cout <<"Add: Overflow" << endl;
        cout<<"A+B = " <<C.long_val() << endl;
    } else {
        cout <<"Add: Not Overflow" << endl;
        cout<<"A+B = " <<C.value() << endl;
    }
    cout << '\n';
    
    if(D.overflow()){
        cout <<"Minus: Overflow" << endl;
        cout<<"A-B = " <<D.long_val() << endl;
    } else {
        cout <<"Minus: Not Overflow" << endl;
        cout<<"A-B = " <<D.value() << endl;
    }
    cout << '\n';
    
    if(E.overflow()){
        cout <<"Multiply: Overflow" << endl;
        cout<<"A*B = " <<E.long_val() << endl;
    } else {
        cout <<"Multiply: Not Overflow" << endl;
        cout<<"A*B = " <<E.value() << endl;
    }
    cout << '\n';
    
    if(F.is_div_zero()){
        cout<< "Error: Divided by zero" << endl;
    } else {
        cout <<"Divide" << endl;
        cout<<"A/B = " << F.value() << endl;
    }
    
    // cout<<"A+B = " <<C.value() << endl;
    // cout<<"A+B = " <<C.long_val() << endl;
    // C.overflow() ? cout <<"Overflow\n" : cout << "OK\n" ;
    // cout<<"A-B = " <<D.value() << endl;
    // cout<<"A-B = " <<D.long_val() << endl;
    // D.overflow() ? cout <<"Overflow\n" : cout << "OK\n" ;
    // cout<<"A*B = " <<E.value() << endl;
    // cout<<"A*B = " <<E.long_val() << endl;
    // E.overflow() ? cout <<"Overflow\n" : cout << "OK\n" ;
    // cout<<"A/B = " <<F.value() << endl;
    // F.is_div_zero() ? cout <<"Divided by zero\n" : cout << "OK\n";
    
    return 0;
}
