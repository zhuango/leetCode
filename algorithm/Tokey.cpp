
#include <iostream>
#include <bitset>

using namespace std;

unsigned long PositiveInteger(int i, int M)
{
    // prime number is better.
    return i % M;
}

unsigned long FloatPoint2KeyV1(double i, unsigned long M)
{
    if(i > 0.0 and i < 1)
    {
        //The least significant bits play no role bacause of the truncation to unsigned long long.
        return (unsigned long)(i * M);
    }
    else throw;
}
unsigned long FloatPoint2KeyV2(double i, unsigned long M)
{
    unsigned long c;
    c = ((unsigned long *)(&i))[0];
    return c % M;
}

unsigned long String2Key(string s, unsigned long M)
{
    unsigned long hash = 0;
    unsigned long R = 31;
    for(char c : s)
    {
        hash = ( (hash * R) + c - '0' ) % M;
    }
    return hash;
}

unsigned long Components2Key(int year, int month, int day, unsigned long M)
{
    unsigned long hash = 0;
    unsigned long R = 31;
    hash = ( ( (day*R + month) % M ) * R + year ) % M;
    return hash;
}
void doubletostrV1(double* a, char* str){
	unsigned long c;
	c= ((unsigned long*)a)[0]; 
	for(int i=0;i<64;i++){
		str[63-i]=(char)(c&1)+'0';
		c>>=1;
	}
	str[64] = '\0';
    cout << str << endl;
}

void doubletostrV2(double a)
{
    unsigned long c;
    c = ((unsigned long *)(&a))[0];
    bitset<sizeof(double)*8> l(c);
    cout << l << endl;
    cout << l.to_ulong() % 100 << endl;
}
int main(void)
{
    cout << "float size (Bytes): " << sizeof(float) << endl;
    cout << "double size (Bytes):" << sizeof(double) << endl;
    cout << "long long (Bytes) : " << sizeof(long) << endl;
    cout << FloatPoint2KeyV2(0.82, 100)  << endl;
    double input = 0.82;
    char str[65];
    doubletostrV1(&input, str);
    doubletostrV2(input);
    cout << String2Key("liuzhuang", 100) << endl;
    cout << Components2Key(2017, 7, 19, 100) << endl;
}