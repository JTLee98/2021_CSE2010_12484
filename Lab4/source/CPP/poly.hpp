#pragma once

struct Term
{
	Term();
	Term(unsigned int p_exp, int p_coeff);
	Term(unsigned int p_exp, int p_coeff, Term* p_next);

	unsigned int exp;
	int coeff;
	Term* next;
};

class Polynomial
{
private:
	Term* m_head;
	unsigned int m_count;
	int m_order; // set this to -1 if poly is empty

public:
	Polynomial(); // createpoly
	~Polynomial();

	void clear(); // clearpoly
	const char* printToBuff() const; // printpoly_impl
	void print() const; // printpoly
	void addTerm(unsigned int p_exp, int p_coeff); // addTerm
	friend Polynomial operator*(Polynomial A, Polynomial B);
};

Polynomial operator*(Polynomial A, Polynomial B);
