using namespace std;

template <typename type>
void fibHeap::insert(type key){
	if(this->minKey == NULL){
		minKey = new node<type>(key);
		rootLIst.push_back(minKey);
	}
	else{
		temp = new node<type>(key);
		rootList.push_back(temp);
		if(temp < minKey)
			minKey = temp;
	}
}