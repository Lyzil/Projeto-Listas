/******************************************************************************

OBSERVAÇÕES:

a) Não poderão ser cadastrados funcionários com mesmo prontuário;

b) A pesquisa de funcionário deverá utilizar o atributo "Prontuário" como 
critério e, quando encontrado, deverão ser exibidos os demais atributos;

c) A listagem dos funcionários deverá apresentar todos os seus atributos e, 
ao final, informar o total dos salários.

*******************************************************************************/
#include <iostream>
using namespace std;


struct Funcionario
{
	int prontuario;
	string nome;
	double salario;
	Funcionario *ant;
};

Funcionario* init()
{
	return NULL;
}

bool isEmpty(Funcionario* funcionario)
{
	return (funcionario == NULL);
}

Funcionario* insert(Funcionario* funcionario, int i, string n, double s)
{
	Funcionario* novo = new Funcionario();
	novo->prontuario = i;
	novo->nome = n;
	novo->salario = s;
	novo->ant = funcionario;
	return novo;
}

void print(Funcionario* funcionario)
{
	Funcionario* aux;
	aux = funcionario;
	double totalSalario = 0.0;
	cout << "--------------" << endl;
	while (aux != NULL)
	{
		cout << "Prontuario: " << aux->prontuario << endl 
		     << "Nome: " << aux->nome << endl
		     << "salario: " << aux->salario << endl;
		totalSalario += aux->salario;
		aux = aux->ant;
		cout << "--------------" << endl;
	}
	cout << "salario total: " << totalSalario << endl;
}

Funcionario* find(Funcionario* funcionario, int i)
{
    Funcionario* aux;
	aux = funcionario;
	while (aux != NULL && aux->prontuario != i)
	{
		aux = aux->ant;
	}
	return aux;
}

Funcionario* remove(Funcionario* funcionario, int i)
{
	Funcionario* aux;
	Funcionario* apoio = NULL;
	
	aux = funcionario;
	while (aux != NULL && aux->prontuario != i)
	{
		apoio = aux;
		aux = aux->ant;
	}
	if (aux == NULL)
	{
		return funcionario;
	}
	
	if (apoio == NULL) // o valor encontrado estava no ultimo elemento
	{
		funcionario = aux->ant;
	}
	else
	{
		apoio->ant = aux->ant;
	}
	free(aux);
	
	return funcionario;
}

int main(int argc, char** argv)
{
	Funcionario *meusFuncionarios;
	meusFuncionarios = init();
    int opcao;
    int novoprontuario, delProntuario, findProntuario;
    string novonome;
    double novosalario;
	
   do{
    cout << "Menu de opções" << endl
                   << "0.	Sair" << endl
                   << "1.	Incluir" << endl
                   << "2.	Excluir" << endl
                   << "3.	Pesquisar" << endl 
                   << "4.	Listar" << endl <<"escolhe a opção que deseja: ";
	cin >> opcao;

switch (opcao) {
    case 0:
        break;
    case 1:{
        cout << "digite o prontuario: ";
        cin >> novoprontuario;
        
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida! Digite apenas números." << endl;
            break;
        }
        if (find(meusFuncionarios, novoprontuario) != NULL) 
        {
            cout << "Erro: já existe um funcionário com esse prontuário!" << endl;
            break;
        }
        
        cout << "digite o nome: ";
        cin.ignore();
        getline(cin, novonome);
        
        bool nomeValido = true;
        for (char c : novonome) {
            if (isdigit(c)) {
                nomeValido = false;
                break;
            }
        }
        
        if (!nomeValido) {
            cout << "Nome inválido! Não pode conter números." << endl;
            break;
        }
        cout << "digite o salario: ";
        cin >> novosalario;
        
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida! Digite apenas números." << endl;
            break;
        }
        meusFuncionarios = insert(meusFuncionarios, novoprontuario, novonome, novosalario);
        break;
    }case 2:
        cout << endl << "digite o prontuario do funcionario que deseja deletar: ";
        cin >> delProntuario;
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida! Digite apenas números." << endl;
            break;
        }
        
        meusFuncionarios = remove(meusFuncionarios, delProntuario);
        break;
    case 3: {
        cout << endl << "digite o prontuario do funcionario que deseja ver: ";
        cin >> findProntuario;
        
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida! Digite apenas números." << endl;
            break;
        }
        
        Funcionario* dadoProcurado = find(meusFuncionarios, findProntuario);
	
	if (dadoProcurado == NULL)
	{
		cout << "Dado nao encontrado" << endl;
	}
    else
    {
        cout << "--------------" << endl;
		cout <<"Dado encontrado: "<< endl << endl <<
		"prontuario: " << dadoProcurado->prontuario << endl <<
		"nome: " << dadoProcurado->nome << endl <<
		"salario: " << dadoProcurado->salario << endl;
		cout << "--------------" << endl << endl;
    }
        break;
    }case 4:
        print(meusFuncionarios);
        break;   
    default:
        cout<< endl <<"Ocorreu um erro, verifique se digitou corretamente"<< endl << endl;
        break;
        
        }
    }while(opcao !=0);
	
	return 0;
}