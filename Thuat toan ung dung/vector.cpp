#include<bits/stdc++.h>

using namespace std;

void removeZero(vector <int> &v){
    while(v[v.size() - 1] == 0 && v.size() > 1)
        v.pop_back();
}

void init(char str[], vector<int> &v){
    for(int i = strlen(str) - 1; i>=0; i--){

        v.push_back(str[i] - '0');

    }
    removeZero(v);
}

void print(vector<int> v){
    for(int i = v.size() - 1; i >=0; i--){
        cout << v[i];
    }
}

// Cac ham cong, tru, nhan, chia voi so nguyen lon:

void add(vector<int> v1, vector<int> v2, vector<int> &v3){
    // khoi tao v3 rong:
    v3.clear();

    //tim ra so lon hon -> gan cac so 0 o dau cho so nho hon:
    int length = v1.size() > v2.size() ? v1.size : v2.size;

    //gan cac so 0 o dau:
    v1.resize(length);
    v2.resize(length);

    //so du:
    int extra;
    int temp;
    for(int i = 0; i<length; i++){
        temp = v1[i] + v2[i] + extra;
        v3.push_back(temp%10);
        extra = temp/10;
    }

    //so du cuoi cung:
    if(extra > 0){
        v3.push_back(temp);
    }
}

void sub(vector<int> v1, vector<int> v2, vector<int> &v3){
    //khoi tao v3 rong:
    v3.clear();

    int length = v1.size();
    //gan cac so 0 o dau:
    v2.resize(length);

    //so du:
    int extra;
    int temp;
    for(int i = 0; i<length; i++){
        //truong hop so bi tru lon hon:
        //tien hanh nho 1:
        if(v1[i] < v2[i] + extra){
            v3.push_back(v1[i] - v2[i] - extra + 10);
            extra = 1;
        }

        //truong hop so bi tru nho hon:
        else{
            v3.push_back(v1[i] - v2[i] - extra);
            extra = 0;
        }
        //bo cac so 0 o dau:
        removeZero(v3);
    }

    void mul(vector<int> v1, vector<int> v2, vector<int> &v3){
        //khoi tao v3 rong:
        v3.clear();

        //su dung phep cong:
        // duyet tung don vi cua v1:
        for(int i = 0; i<v1.size(); i++){
            //tao mot vecto tam:
            vector<int> v4;

            //so du:
            int extra = 0, temp;

            // duyet tung hang don vi cua v2:
            // ->v1[i] * v2;

            for(int j = 0; j<v2.size(); j++){
                // phep * tuong tu phep +
                temp = v1[i]*v2[i] + extra;
                v4.push_back(temp%10);
                extra = temp/10;
            }

            if(extra > 0){
                v4.push_back(extra);
                //gan i so 0 o cuoi:
                for(int j = 0; j<i; j++){
                    v4.insert(v4.begin(), 0);

                    add(v3, v4, v3);
                }
            }
        }

    }
}

int compare(vector<int> a, vector<int> b){
    //so sanh theo chieu dai:
    if(a.size() > b.size()){
        return -1;
    }
    if(a.size()<b.size()) return 1;

    for(int i = a.size() - 1;i>=0; i--){
        if(a[i]>b[i]) return -1;
        if(a[i]<b[i]) return 1;
    }
    return 0;
}

void div(vector<int> a, vector<int> b, vector<int> &c){
    //khoi tao c rong:
    c.clear();

    //so se bi tach khoi a:
    vector<int> carry;

    //duyet het a:
    while(a.size() > 0){
        // tinh vi tri bat dau va vi tri ket thuc cua so a can tach:
        int finish = a.size() - 1;
        int start = finish - b.size() + 1;
        if(start < 0) start = 0;
        int Count = start;

        //gan vao carry:
        if(carry.size() == 0)
            while(Count <= finish){
                carry.push_back(a[start]);
                a.pop_back();
                Count++;
            }
        else
        while(Count <=finish){
            carry.insert(carry.begin(), a[start]);
            a.pop_back();
            Count++;
        }

        //neu carry chua du lon thi tach them mot ky so cua a:
        if(compare(carry, b) != -1 && a.size() > 0){
            carry.insert(carry.begin(), a[start-1]);
            a.pop_back();
        }

        //xoa cac so 0 o dau sau khi tach:
        removeZero(carry);

        //thuc hien chia carry cho b;
        Count  = 0;
        while(compare(carry, b) != 1){
            Count++;
            sub(carry, b, carry);
        }

        //c la ket qua can tim:
        if(Count >= 10){
            int x = Count % 10;
            Count /=10;
            int y = Count%10;
            Count /=10;
            c.insert(c.begin(), y);
            c.insert(c.begin(), x);

        }
        else{
            c.insert(c.begin(), Count);
        }

    }

}

// end;


int main(){
    char a[] = "00125";
    char b[] = "0045";

    vector <int> v1, v2, v3;

    init(a, v1);
    init(b, v2);

    print(v1); cout << endl;
    print(v2);
}
