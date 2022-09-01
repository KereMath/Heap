#pragma once

template<typename T>
class EHeap
{
    private:
        class HandleData
        {
            friend EHeap;
            private:
                T data;
                unsigned position;
        };

        unsigned capacityy;
        unsigned currentSize;
        unsigned head;
        unsigned lastNode;
        unsigned count[13] = {0,0,0};
        unsigned addCount = 0;
        HandleData *heap;
        unsigned *pointedPositions;
        
        
    
        void traverse( unsigned curNode ){
             while( curNode <= currentSize ){
                 if( curNode * 2 > currentSize ) 
                     break;
                 else if( curNode * 2 == currentSize ){
                     if( heap[curNode].data > heap[curNode*2].data ){
                           T temp = heap[curNode].data;
                           heap[curNode].data = heap[curNode*2].data;
                           heap[curNode*2].data = temp;
                           pointedPositions[heap[curNode].position] = curNode*2;
                           pointedPositions[heap[curNode*2].position] = curNode;     
                           unsigned pos = heap[curNode].position;
                           heap[curNode].position = heap[curNode*2].position;
                           heap[curNode*2].position = pos;
                           curNode *=2;
                     }
                     else 
                           break;
                 }
                 else {
                    int newPos = ( heap[curNode*2].data < heap[curNode*2+1 ].data ? curNode*2 : curNode *2 + 1 );
                    if( heap[curNode].data > heap[newPos].data ){
                         T temp = heap[curNode].data;
                           heap[curNode].data = heap[newPos].data;
                           heap[newPos].data = temp;
                           pointedPositions[heap[curNode].position] = newPos;
                           pointedPositions[heap[newPos].position] = curNode;     
                           unsigned pos = heap[curNode].position;
                           heap[curNode].position = heap[newPos].position;
                           heap[newPos].position = pos;
                           curNode = newPos;
                    }
                    else break;
             
                 }
            }
        }

    public:
        typedef HandleData * Handle;

        // Constructs an empty e-heap with a fixed capacity.
        EHeap(unsigned capacity) {
          heap =  new HandleData[capacity * 2];
          pointedPositions = new unsigned [ capacity * 2] ;
          capacityy = capacity;
          currentSize = 0;
        }

        unsigned size() const {
            return currentSize;
        }

        Handle push(T t) {
          
          heap[currentSize+1].data = t;
          heap[currentSize+1].position = currentSize+1;
          pointedPositions[currentSize+1] = currentSize + 1;
          // if( currentSize > 2 ) 
           //    return newNode;
           if( currentSize == 0 ){
               currentSize = 1;
               return heap + currentSize;
            }
            currentSize++;
            //return heap + currentSize;
            int curNode = currentSize;

            while( curNode > 1 && heap[curNode].data <= heap[curNode/2].data ){
               T temp = heap[curNode].data;
               heap[curNode].data = heap[curNode/2].data;
               heap[curNode/2].data = temp;
               pointedPositions[heap[curNode].position] = curNode/2;
               pointedPositions[heap[curNode/2].position] = curNode;     
               unsigned pos = heap[curNode].position;
               heap[curNode].position = heap[curNode/2].position;
               heap[curNode/2].position = pos;
               curNode /= 2;
            }
            return heap + currentSize;
        }

        T pop() {
          T poppedValue = heap[1].data;
          heap[1].data = heap[currentSize].data;
          heap[1].position = heap[currentSize].position;
          pointedPositions[heap[currentSize].position] = 1;
          currentSize--;
          //return poppedValue;
          if( currentSize > 1 )
          traverse( 1 );
          return poppedValue;
        }

        T erase(Handle handle) { 
          T erasedValue = heap[pointedPositions[ handle - heap]].data;
          unsigned posToBeDeleted = pointedPositions[ handle - heap];
          heap[posToBeDeleted].data = heap[currentSize].data;
          heap[posToBeDeleted].position = heap[currentSize].position;
          pointedPositions[heap[currentSize].position] = posToBeDeleted;
          currentSize--;
          //return poppedValue;
          if( posToBeDeleted != currentSize - 1)
          traverse( posToBeDeleted );
          return erasedValue;
          
        }

        ~EHeap() { 
         delete [] heap;
         delete [] pointedPositions;
}
};