#include<iostream>
using namespace std;
 
// Function to extend the key to the length of plaintext
string get_full_key(string pt, string k){
    if(k.size() >= pt.size())
        return k;
    else{
        int psize = pt.size()-k.size();
        int ksize = k.size(); 
        while(psize >= ksize){
            k += k;
            psize -= ksize;
        }
 
        k += k.substr(0, psize);
        return k;
    }
}
 
// Encryption Function
string get_encryption(string pt, string k){
 
    string ct = "";
    for(int i=0;i<pt.size();i++)
        ct += (char) (((int)pt[i]-'A' + (int)k[i]-'A') % 26) + 'A';
 
    return ct;
}
 
// Decryption Function
string get_decryption(string ct, string k){
 
    string pt = "";
    for(int i=0;i<ct.size();i++)
        pt += (char) ((((int)ct[i]- 'A' - (k[i] -'A')) + 26) % 26) + 'A';
 
    return pt;
}
 
int main(){
	int operation; 
    cout<<"Choose your operation (encryption(1) or decryption(2)):";
    cin>> operation;
    
    if(operation == 1){
	
    // The Plaintext
    
    string plaintext;
   cout<<"Enter the Plaintext:\n";
   cin>> plaintext;
    // The key
    string key;
    cout<<"Enter the Key:\n";
   cin>> key;
 
    // Function call to extend the key size
    key = get_full_key(plaintext, key);
    
   // Function call to encode the data
    string ciphertext = get_encryption(plaintext, key);
    
    cout<<" Plaintext : "<< plaintext <<endl;
 
    cout<<" Key: "<< key <<endl;
 
    cout<<" Ciphertext: "<< ciphertext <<endl;
}
else if(operation == 2){
	string d_plaintext;
         // The Ciphertext
    string ciphertext;
    
   cout<<"Enter the Ciphertext:\n";
   cin>> ciphertext;
    // The key
    string key;
    cout<<"Enter the Key:\n";
   cin>> key;
      // Function call to extend the key size
    key = get_full_key(ciphertext, key);
 
    // Function call to decode the data
    d_plaintext = get_decryption(ciphertext, key);
    
    cout<<" Ciphertext: "<<ciphertext<<endl;
    
    cout<<" Key: "<<key<<endl;
 
    cout<<" Decrypted Plaintext: "<<d_plaintext<<endl;
 
    return 1;
}
    else {
    	cout<<"Choose the correct operation";
	}
	
	
}