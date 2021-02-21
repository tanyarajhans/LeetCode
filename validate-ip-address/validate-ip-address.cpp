class Solution {
public:
    int helper1(string s){
        int n=s.size();
        if(s[n-1]=='.') return -1;
        vector<string>v;
        string temp;
        stringstream ss(s);
        while(getline(ss,temp,'.')){
            if(temp.size()==0) return -1;
            v.push_back(temp);
        }
        if(v.size()>4 || v.size() <4) return -1;
        for(auto i:v){
            if(i.size()>3 || i.size()<1) return -1;
            for(auto j:i){
                if(isalpha(j)) return -1;
            }
            int num=stoi(i);
            if(num==0 && i.size()>=2) return -1;
            if(num>0 && i[0]=='0') return -1;
            if(num>255 || num<0 ) return -1;
        }
        return 1;
    }
    bool ischaracter(char c){
        if(isdigit(c)) return true;
        if(isalpha(c)){
            if(c=='a' || c=='b'|| c=='c'||c=='d'||c=='e'||c=='f' || c=='A'|| c=='B'|| c=='C'||c=='D' ||c=='E'|| c=='F') return true;
            else return false;
        }
        return false;
    }
    int helper2(string s){
        if(s.size()<15) return -1;
        vector<string>v;
        string temp;
        stringstream ss(s);
        int n=s.size();
        if(s[n-1]==':') return -1;
        while(getline(ss,temp,':')){
            if(temp.size()==0) return -1;
            v.push_back(temp);
        }
        if(v.size()<8 || v.size()>8) return -1;
        for(auto i:v){
            if(i.size()>4 ||i.size()<1) return -1;
            for(auto j:i){
                if(!ischaracter(j)) return -1;
            }
        }
        return 1;
    }
    string validIPAddress(string IP) {
        if(IP.size()==0) return "Neither";
        if(helper1(IP)==1) return "IPv4";
        if(helper2(IP)==1) return "IPv6";
        return "Neither";
    }
};