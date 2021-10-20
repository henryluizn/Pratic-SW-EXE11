#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <list>

#include "Pessoa.hpp"

class SalaAula;

class Disciplina{
	friend class SalaAula;
	public:
		Disciplina(std::string nome, SalaAula* sala);

		std::string getNome();
		void setNome(std::string nome);
		
		int getCargaHoraria();
		void setCargaHoraria(unsigned int cargaHoraria);
		
		Pessoa* getProfessor();
		void setProfessor(Pessoa* professor);
		
		void adicionarAluno(Pessoa* aluno);
		void removerAluno(Pessoa* aluno);
		void removerAluno(unsigned long cpf);
		std::list<Pessoa*>& getAlunos();

		void imprimeDados(std::string& cabecalho, unsigned int& cargaTotalCurso);

		void setSala(SalaAula* sala);
		SalaAula* getSala();
		void imprimeSala();

	private:
		std::string nome;
		unsigned short int cargaHoraria;

		Pessoa* professor;
		std::list<Pessoa*> alunos;
		SalaAula* sala;
};
#endif
