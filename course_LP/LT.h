#pragma once
#include "cstring"
#define LEXEMA_FIXSIZE		1			// size length lexema
#define	LT_MAXSIZE			4096		// maximal size lexem	
#define	LT_TI_NULLXDX		0xffffffff	// not link table ID			
#define LEX_OVERFLOW		'o'			// on/off control overflow
#define LEX_BOOL			't'			// type data bool
#define	LEX_LONG			't'			// type data long
#define	LEX_CHAR			't'			// type data byte
#define LEX_FLOAT			't'			// float data type
#define	LEX_STRING			't'			// type data string
#define LEX_TYPE			't'			// all types data
#define	LEX_ID				'i'			// ������� ��� ��������������
#define	LEX_LITERAL			'l'			// ������� ��� ��������
#define	LEX_FUNCTION		'f'			// ������� ��� function
#define	LEX_RETURN			'r'			// ������� ��� return
#define LEX_MAIN			'm'			// ������� ��� main
#define	LEX_SEMICOLON		';'			// ������� ��� ;
#define	LEX_COMMA			','			// ������� ��� ,
#define	LEX_LEFTBRACE		'{'			// ������� ��� {
#define	LEX_RIGHTBRACE		'}'			// ������� ��� }
#define	LEX_LEFTHESIS		'('			// ������� ��� (
#define	LEX_RIGHTESIS		')'			// ������� ��� )
#define	LEX_ASSIGN			'='			// ������� ��� =
#define	LEX_PLUS			'v'			// ������� ��� +
#define	LEX_MINUS			'v'			// ������� ��� -
#define	LEX_STAR			'v'			// ������� ��� *
#define	LEX_DIRSLASH		'v'			// ������� ��� /
#define EXPRESSIONS			'v'			// ������ ��� ���� ���������
#define LEX_LESS			'c'			// symbol compare <
#define LEX_MORE			'c'			// symbol compare >
#define LEX_EQUALS			'c'			// symbol compare ==
#define LEX_NOT_EQUALS		'c'			// symbol compare !=
#define LOGICALS			'c'			// all expressions >= <=
#define LEX_XOR				'b'			// symbol compare ^
#define LEX_INVERSION		'b'			// symbol compare ~
#define LEX_AND				'b'			// symbol compare |
#define LEX_OR				'b'			// symbol compare &
#define LEX_SHR				'b'			// symbol compare >>
#define LEX_SHL				'b'			// symbol compare <<
#define BINARY				'b'
#define LEX_WRITE			'w'			// write to console
#define LEX_WRITEL			'w'			// write to console
#define LEX_SQUARE_RIGHT	']'			// right square less
#define LEX_SQUARE_LEFT		'['			// left square less
#define LEX_REPEAT			'p'			// repeat
#define LEX_UNTIL			'u'			// until
#define LEX_IF				'z'			// IF
#define LEX_ELSE			'e'			// ELSE
#define LEX_INCORDEC		'n'			// ++ or --

namespace LT									// ������� ������
{
	struct Entry								// ������ ������� ������
	{
		char lexema[LEXEMA_FIXSIZE + 1];		// �������
		char expression[LEXEMA_FIXSIZE + 2];	// ��������� +,-,/,*
		int sn;									// ����� ������ � �������� ������
		int idxTI;								// ������ � ������� ��������������� ��� LT_TI_NULLIDX
		Entry()
		{
			memset(lexema, 0x00, LEXEMA_FIXSIZE + 1);
			memset(expression, 0x00, LEXEMA_FIXSIZE + 2);
			sn = 0;
			idxTI = LT_TI_NULLXDX;
		}
		Entry(char a, int i) {
			lexema[0] = a;
			lexema[1] = 0x00;
			sn = i;
		}
	};

	struct LexTable								// ��������� ������� ������
	{
		int maxsize;							// ������� ������� ������ < LT_MAXSIZE
		int size = 0;							// ������� ������ ������� ������ < maxsize
		Entry* table;							// ������ ����� ������� ������
	};

	LexTable Create(int);						// ������� ������� ������
	Entry Create(char, int);
	void Add(LexTable*, Entry);					// ���������� ������
	Entry GetEntry(LexTable&, int);				// �������� ������ ������� ������
	void PrintTableLex(LexTable*, wchar_t*);		// ���������� ������� ������
	void Delete(LexTable&);						// ������� ������� ������ (���������� ������)

};