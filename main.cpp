#include <iostream>
#include <string>
#include <list>

#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "SalaAula.hpp"


int main(){

// criando salas 
	SalaAula sala1{"Lab Info 1", 20};
	SalaAula sala2{"PA01", 15};
	SalaAula sala3{"Auditorio-DINF ", 10};

// criando 1 disciplina
	Pessoa prof1{"João", 40};
	Disciplina dis1{"Orientacao a Objetos", &sala1};
	dis1.setProfessor(&prof1);

// criando 2 disciplina
	Pessoa prof2{"Maria", 30};	
	Disciplina dis2{"Sistemas Operacionais", &sala2};
	dis2.setProfessor(&prof2);

// criando 2 disciplina
	Pessoa prof3{"Paulo", 25};	
	Disciplina dis3{"Compiladores", &sala2};
	dis3.setProfessor(&prof3);

// sets das salas nas diciplinas
	dis1.setSala(&sala1);
	dis2.setSala(&sala2);
	dis3.setSala(&sala2);

// imprimindo sala de aula de acordo com a disciplina
	std::cout << "\n\n----------- Imprimindo as salas de aulas vinculadas nas diciplinas -----------" << std::endl;
	dis1.imprimeSala();
	dis2.imprimeSala();
	dis3.imprimeSala();
	std::cout << "\n\n----------- Imprimindo as diciplinas vinculadas nas salas de aulas -----------" << std::endl;
	sala1.imprimirSalaEDisciplina();
	sala2.imprimirSalaEDisciplina();
	sala3.imprimirSalaEDisciplina();

// setando nova sala de aula da segunda disciplina pelo objeto da DISCIPLINA
	std::cout << "\n\n----------- Alterando a sala da disciplina " << dis2.getNome() << " -----------" << std::endl;
	dis2.setSala(&sala3);

// imprimindo sala de aula 
	dis2.imprimeSala();
	std::cout << "\n\n----------- Imprimindo as diciplinas vinculadas nas salas de aulas apos a alteracao -----------" << std::endl;
	sala1.imprimirSalaEDisciplina();
	sala2.imprimirSalaEDisciplina();
	sala3.imprimirSalaEDisciplina();
	
// setando a nova sala de aula da primeira disciplina pelo objeto da SALA DE AULA
	std::cout << "\n\n----------- Alterando a sala da disciplina " << dis1.getNome() << " atraves do objeto sala de aula -----------" << std::endl;
	sala2.adicionarDisciplina(&dis1);
	dis1.imprimeSala();
	std::cout << "\n\n----------- Imprimindo as diciplinas vinculadas nas salas de aulas apos a alteracao -----------" << std::endl;
	sala1.imprimirSalaEDisciplina();
	sala2.imprimirSalaEDisciplina();
	sala3.imprimirSalaEDisciplina();
	
	return 0;
}
