#pragma once
#define ID_MAXSIZE		10										// ������������ ���������� ������� � ��������������
#define	PREFIX_SIZE		10
#define EXT_FUNCTION	32
#define TI_MAXSIZE		4096									// ������������ ���������� ��-�� � ������� ��������������� 
#define TI_LONG_DEFAULT	0x00000000								// �������� �� ��������� ��� ���� integer 
#define TI_DEFAULT		0x00									// �������� �� ��������� ��� ���� string 
#define TI_NULLIDX		0xffffffff								// ��� �������� ������� ���������������
#define TI_STR_MAXSIZE	255
#define PARM_ID_DEFAULT_EXT L"file.id.txt"						// ����� ��������������� � ���������
#define FLOAT_MAX		3.4028235E+38
#define FLOAT_MIN		-3.4028235E+38

namespace IT													// ������� �������������
{
	enum IDDATATYPE { NUL, LONG, STR, CHAR, FLOAT, BOOL };		// ���� ������ ���������������: integer, string, byte
	enum IDTYPE		{ N, V, F, P, L, S, E , A, C, W, K, PA};	// ���� ���������������: ����������, �������, ��������, 
																// �������, ������� �������, ������, ���������, ���������
	enum CALCULUS	{ NC, DEC, OCT, HEX, BIN };					// ������� ����������
	
	struct Entry												// ������ ������� ���������������
	{
		int idxfirstLE;											//  
		char id[ID_MAXSIZE + 1];								// ������������� (������������� ��������� �� ID_MAXSIZE
		char prefix[PREFIX_SIZE + 1];							// ������� ���������
		char extfunct[EXT_FUNCTION + 1];						// ������� �������
		int parametresfunc;
		IDDATATYPE iddatatype;									// ��� ������
		IDTYPE idtype ;											// ��� ��������������
		CALCULUS idcalculus;
		union
		{
			unsigned char vchar;
			unsigned int vint;									// �������� integer
			float vfloat;
			bool vbool;

			struct
			{
				unsigned char len;						// ���������� �������� � string
				char str[TI_STR_MAXSIZE - 1];			// ������� string
			} 
			vstr[TI_STR_MAXSIZE];						// �������� string
		}value;											// �������� ��������������

		Entry()
		{
			idxfirstLE = TI_NULLIDX;
			memset(prefix, 0x00, PREFIX_SIZE);
			memset(id, 0x00, ID_MAXSIZE);
			memset(extfunct, 0x00, EXT_FUNCTION);
			parametresfunc = 0;
			iddatatype = NUL;
			idtype = N;
			idcalculus = NC;
			value.vint = 0;
			value.vbool = 0;
			value.vchar = 0;
		}
	};

	struct IdTable											// ��������� ������� ���������������
	{
		int maxsize;										// ������� ������� ��������������� < TI_MAXSIZE
		int current_size;									// ������� ������ ������� ��������������� < maxsize
		Entry* table;										// ������ ����� ������� ���������������
	};

	IdTable Create(int);
	void Add(IdTable&, Entry);								// �������� � ������ ���������������
	Entry GetEntry(IdTable&, int n);						// �������� ������ ������� ���������������
	Entry AddLiteral(Entry&);								// 
	int IsId(IdTable&,LT::LexTable&, char[], char[], int, bool, IDDATATYPE,IDTYPE);					// ������� : ������� ������ (���� ����), TI_NULLIDX(���� ���)
	int IsLiteral(IdTable&, char*);							// ������ IT_TI_NULLIDX ���� ���� ��� ���������� �������������
	int IsLiteral(IdTable&, unsigned int);					// ������ IT_TI_NULLIDX ���� ���� ��� ���������� �������������
	int IsLiteral(IdTable&, unsigned char);					// ������ IT_TI_NULLIDX ���� ���� ��� ���������� �������������
	int IsLiteral(IdTable&, float);							// ������ IT_TI_NULLIDX ���� ���� ��� ���������� �������������
	int LiteralCreate(IdTable,LT::LexTable, char*, int, bool&,bool);	// �������� ������� � �������
	void PrintIdTable(const wchar_t* in, IdTable&);			// ������ ������� ���������������
	void Delete(IdTable&);									// ������� ������� ������ (���������� �����)
	Entry Reset();
}