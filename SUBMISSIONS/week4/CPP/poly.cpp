#include "poly.hpp"
#include <iostream>
#include <sstream>


Term::Term()
	:exp(0), coeff(0), next(nullptr) {}

Term::Term(unsigned int p_exp, int p_coeff)
	: exp(p_exp), coeff(p_coeff), next(nullptr) {}

Term::Term(unsigned int p_exp, int p_coeff, Term* p_next)
	: exp(p_exp), coeff(p_coeff), next(p_next) {}


Polynomial::Polynomial()
	:m_head(nullptr), m_count(0), m_order(-1) {}

Polynomial::~Polynomial() {}

void Polynomial::clear()
{
	Term* iter = nullptr, *temp = nullptr;
	if (m_count == 0 or m_head == nullptr) return;
	else for (iter = m_head; iter != nullptr; iter = temp)
	{
		temp = iter->next;
		free(iter);
	}
	m_head = nullptr;
	m_count = 0;
	m_order = -1;
}

const char* Polynomial::printToBuff() const
{
	std::stringstream msg;
	Term* iter = nullptr;

	if (m_order == -1 or m_count == 0)
	{
		// msg << "polynomial at " << this << " is empty.\n";
		msg << " 0";
	}
	else
	{
		msg << " ";
		// msg << m_order << "th order polynomial at " << this << ": \n";
		for (iter = m_head; iter != nullptr; iter = iter->next)
		{
			if (iter->coeff > 0 and iter != m_head)
				msg << "+" << iter->coeff << "x^" << iter->exp;
			else msg << iter->coeff << "x^" << iter->exp;
		}
		//msg << '\n';
	}
	
	char* output = new char[1024];
	strcpy_s(output, 1024, msg.str().c_str());
	return output;
}

void Polynomial::print() const
{
	Term* iter = nullptr;

	if (m_order == -1 or m_count == 0)
	{
		std::cout << "polynomial at " << this << " is empty.\n";
	}
	else
	{
		std::cout << m_order << "th order polynomial at " << this << ": \n";
		for (iter = m_head; iter->next != nullptr; iter = iter->next)
		{
			if(iter->coeff > 0)
				std::cout << '+' << iter->coeff << "x^" << iter->exp;
			else std::cout << iter->coeff << "x^" << iter->exp;

		}
		std::cout << '\n';
	}
	return;
}

void Polynomial::addTerm(unsigned int p_exp, int p_coeff)
{
	if (p_coeff == 0) return;
	if ((int)p_exp > m_order)
	{
		Term* new_head = new Term(p_exp, p_coeff, m_head);
		m_head = new_head;
		m_order = p_exp;
	}
	else
	{
		Term* prev = nullptr;  
		Term* iter = m_head;
		while (iter->exp > p_exp)
		{
			prev = iter;
			iter = iter->next;
			if (iter == nullptr)
			{
				Term* new_term = new Term(p_exp, p_coeff, iter);
				prev->next = new_term;
				m_count++;
				return;
			}
		}
		if (iter->exp == p_exp)
		{
			iter->coeff += p_coeff;
			if (iter->coeff == 0) // remove term
			{
				prev->next = iter->next;
				free(iter);
				return;
			}
		}
		else
		{
			Term* new_term = new Term(p_exp, p_coeff, iter);
			prev->next = new_term;
		}
	}
	m_count++;
	return;
}

Polynomial operator*(Polynomial A, Polynomial B)
{
	Polynomial AB;
	unsigned int i = 0, j = 0;
	Term* i_A = A.m_head;
	Term* i_B = B.m_head;
	for (i_A = A.m_head; i_A != nullptr; i_A = i_A->next)
		for (i_B = B.m_head; i_B != nullptr; i_B = i_B->next)
			AB.addTerm(i_A->exp + i_B->exp, i_A->coeff * i_B->coeff);
	return AB;
}
