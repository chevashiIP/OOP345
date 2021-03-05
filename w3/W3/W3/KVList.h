#ifndef _KVLIST_H_
#define _KVLIST_H_

template<typename K, typename V, int N>
class KVList
{
	K m_key[N];                                        
	V m_value[N];                                        
	int m_arrays;                                       
public:
	KVList() { m_arrays = 0; };                          
	size_t size() const { return m_arrays; }             
	const K& key(int i) const { return m_key[i]; }     
	const V& value(int i) const { return m_value[i]; };  

	KVList& add(const K& k, const V& v)        
	{
		if (m_arrays < N)
		{
			m_key[m_arrays] = k;
			m_value[m_arrays] = v;
			m_arrays++;
		}
		return *this;
	}

	int find(const K& k) const                 
	{
		int f;

		for (int i = 0; i < m_arrays; i++)
		{
			if (m_key[i] == k)
			{
				f = i;
			}
		}

		return f;
	}

	KVList& replace(int i, const K& k, const V& v)  
	{
		if (i > 0 && i < m_arrays)
		{
			m_key[i] = k;
			m_value[i] = v;
		}
		return *this;
	}
};

#endif
