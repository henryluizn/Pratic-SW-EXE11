#include <iostream>

#include "SalaAula.hpp"
#include "Disciplina.hpp"

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
	:nome{nome}, capacidade{capacidade}{
}
    
std::string SalaAula::getNome(){
	return nome;
}

void SalaAula::setNome(std::string nome){
	this->nome = nome;
}

unsigned int SalaAula::getCapacidade(){
	return capacidade;
}

void SalaAula::setCapcidade(unsigned int capacidade){
	this->capacidade = capacidade;
}


// atualiza o objeto da classe SalaAula e da classe Disciplina utilizando a função "setSala" da classe Disicplina.
void SalaAula::adicionarDisciplina(Disciplina* disciplina)
{
	// disciplina->setSala(this);
	if (disciplina != nullptr && disciplina->sala != nullptr)
	{
		disciplina->sala->removerDisciplina(disciplina);
		disciplina->sala = this;
		this->disciplinas.push_back(disciplina);
	}
	
}


void SalaAula::removerDisciplina(Disciplina* disciplina)
{
	this->disciplinas.remove(disciplina);
}


std::list<Disciplina*>& SalaAula::getDisciplinas()
{
	return disciplinas;
}


void SalaAula::imprimirSalaEDisciplina()
{
	std::list<Disciplina*>::iterator it{this->disciplinas.begin()};

	if (this->disciplinas.size() > 0)
	{
		std::cout << "\nA sala " << this->getNome() << " possui as seguintes disciplinas:" << std::endl;
		while (it != this->disciplinas.end())
		{
			std::cout << "\n\t"<< (*it)->getNome() << std::endl;
			it++;
		}
	}else{
		std::cout << "\nA sala de aula " << this->getNome() << " não possui disciplinas vinculadas!" << std::endl;
	}
}