#include "arquivo.h"
void manipulate(char* str, int tmp, int i, FILE* fp){
	while(( tmp >= 'a' && tmp <= 'z' || tmp >= 'A' && tmp <= 'Z' || tmp >= '0' && tmp <= '9' )){
            str[i] = tolower(tmp);
            tmp = fgetc(fp);
            if(tmp == EOF)
            	break;
            i++;
    	}
}

Arquivo::Arquivo(string e, string m){
	_end = e;
	_mode = m;
	_state = 0;
}

void Arquivo::open(){
	fp = fopen(_end.c_str(),_mode.c_str());
	_state = 1;
	if(!fp){
		cout << "Erro ao abrir o arquivo. " << endl;
		_state= 0;
	}
}
FILE* Arquivo::getfp(){
	return (fp);
}
string Arquivo::end(){
	return (_end);
}

void Arquivo::vocabulary(string end){
	FILE* v;
	v = fopen(end.c_str(),"w+");
	char str[20];
	int i,tmp,j = 0,q =0;
    while(!feof(fp) && !ferror(fp)){
        tmp = fgetc(fp);
        i = 0;
        while(( tmp >= 'a' && tmp <= 'z' || tmp >= 'A' && tmp <= 'Z' || tmp >= '0' && tmp <= '9' )){
            str[i] = tolower(tmp);
            tmp = fgetc(fp);
            if(tmp == EOF)
            	break;
            i++;
    	}
        str[i] = '\0';
    	fputs(str,v);
        if(tmp == ' ' || tmp == '\n')
        	fputs("\n",v);
		j++;
	}
	fputs("\n",v);
	fclose(v);
}

void Arquivo::to_vector(vector<string> &v){
	ifstream inFile(this->_end);
	string palavra;
	while(!(inFile.eof())){
		getline(inFile,palavra);
		v.push_back(palavra);
	}
	v.pop_back();
	inFile.close();
};

void Arquivo::to_file(vector<string> &v){
	ofstream outFile(this->_end);
	string palavra;
	for(int i = 0;i<v.size();i++){
		outFile << v[i] << "\n";
	}
};

int Arquivo::size(){
	int _size = -1;
	string trash;
	ifstream inFile(this->_end);
	while(!inFile.eof()){
		getline(inFile,trash);
		_size++;
	}
	return _size;
};

void Arquivo::ordenate(){
	ifstream inFile(this->_end);
	string palavra;
	int r;
	map<string,int> m;
	
	while(!inFile.eof()){
		getline(inFile,palavra);
		if(palavra != "")
			m[palavra] = 0;
	}
	
	inFile.close();
	
	ofstream onFile("ORD_"+_end);
	map<string,int>::iterator it;
	
	for(it=m.begin();it!=m.end();it++){
		onFile << it->first << "\n";
	}                       
	
	onFile.close();
};

void Arquivo::to_map(map<string,set<string>*> &m){
	ifstream inFile(this->_end);
	string palavra;
	while(!inFile.eof()){
		set<string>* aux = new set<string>;
		getline(inFile,palavra);
		if(palavra != ""){
			m[palavra] = aux;
		}
	}
	inFile.close();
};

void Arquivo::print(){
	ifstream inFile(this->_end);
	char c;
	while(inFile.get(c)){
		cout << c;
	}
	inFile.close();
};

void Arquivo::close(){
	fclose(fp);
};
