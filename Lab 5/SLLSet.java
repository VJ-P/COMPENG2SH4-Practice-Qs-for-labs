package Main;

public class SLLSet {

    int size;                                                                   //variable to store teh size of the set
    SLLNode head;                                                               //reference variable to teh beginning of the list

    public SLLSet() {                                                            //constructor for an empty SLLSet
        size = 0;                                                               //makes size equal to 0 and points the first node to null
        head = null;
    }

    public SLLSet(int[] sortedArray) {
        if (sortedArray.length > 0){
            size = sortedArray.length;
            SLLNode p = new SLLNode(sortedArray[0], null);
            head = p;
            for (int i = 1; i < size; i++) {
                p.next = new SLLNode(sortedArray[i], null);
                p = p.next;
            }
        }
        else{
            size = 0;
            head = null;
        }
    }

    public int getSize() {                                                       //method to return the size of the linked list
        return size;                                                            //returns the size
    }

    public SLLSet copy() {
        SLLSet newSet = new SLLSet();
        if (head != null){
            newSet.size = this.size;
            int[] tempArray;
            SLLNode p = head;
            tempArray = new int[newSet.size];
            for (int i = 0; i < size; i++) {
                tempArray[i] = p.value;
                p = p.next;
            }
            newSet = new SLLSet(tempArray);
        }
        return newSet;
    }

    public boolean isIn(int v) {
        int count = 0;
        for(SLLNode p = head; p != null; p = p.next){
            if(p.value == v){
                count += 1;
            }
        }
        if (count == 0){
            return false;
        }
        else{
            return true;
        }
    }
    
    public void add(int v){
        for(SLLNode p = head; p != null; p = p.next){
            if(this.isIn(v)== false){
            if(v > p.value && p.next == null){
                SLLNode u = new SLLNode(v, null);
                    p.next = u;
                    size += 1;
                    break;
                }
                if(v < p.next.value && v > p.value){
                    p.next = new SLLNode(v, p.next);
                    size += 1;
                    break;
                }
                else if(v < p.value && p == head){
                    head = new SLLNode(v, head);
                    size += 1;
                    break;
                }
            }
        }
    }
    
    public void remove(int v){
        if(isIn(v)==true){
            for(SLLNode p = head; p != null; p = p.next){
                if(p.next.next == null && v == p.next.value){
                    p.next = null;
                    size -= 1;
                    break;
                }
                else if(v == p.value && p==head){
                    head = p.next;
                    size -= 1;
                    break;
                }
                else if(v == p.next.value){
                    p.next = p.next.next;
                    size -= 1;
                    break;
                }
            }
        }
    }
    
    public SLLSet union(SLLSet s){
        SLLSet newSet = this.copy();
        for(SLLNode p = s.head; p != null; p = p.next){
            newSet.add(p.value);
            newSet.size += 1;
        }
        return newSet;
    }
    
    public SLLSet intersection(SLLSet s){
        SLLSet newSet = this.copy();
        for(SLLNode p = newSet.head; p != null; p = p.next){
            if(s.isIn(p.value) == false){
                newSet.remove(p.value);
                size -= 1;
            }
        }
        return newSet;
    }
    
    public SLLSet difference(SLLSet s){
        SLLSet newSet = this.copy();
        for(SLLNode p = newSet.head; p != null; p =p.next){
            if(s.isIn(p.value) == true){
                newSet.remove(p.value);
                size -= 1;
            }
        }
        return newSet;
    }
    
    public static SLLSet union(SLLSet[] sArray){
        SLLSet newSet = sArray[0].copy();
        for(int i = 1; i < sArray.length; i++){
            newSet = newSet.union(sArray[i]);
        }
        return newSet;
    }

    public String toString() {
        String s = new String();
        s += "[";
        for(SLLNode p = head; p != null; p = p.next){
            s += p.value;
            if (p.next != null) {
                s += ", ";
            }
        }
        s += "]";
        return s;
    }
}
