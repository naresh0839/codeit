struct func {
	bool operator() (const pii &a, const pii &b) const {
		int lena = a.S - a.F + 1;
		int lenb = b.S - b.F + 1;
		if (lena == lenb) return a.F < b.F;
		return lena > lenb;
	}
};
