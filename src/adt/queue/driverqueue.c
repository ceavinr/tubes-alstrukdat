#include "queue.h"

int main() {
    printf("\nMake QUEUE\n");
    Queue queue = MakeQueue();
    displayQueue(queue);

    printf("\nEnqueue = \"ANTRIAN 01\" \n");
    Word satu = stringToWord("ANTRIAN 01");
    enqueue(&queue, satu);
    displayQueue(queue);

    printf("\nEnqueue = \"ANTRIAN 02\" \n");
    Word dua = stringToWord("ANTRIAN 02");
    enqueue(&queue, dua);
    displayQueue(queue);

    printf("\nEnqueue = \"ANTRIAN 03\" \n");
    Word tiga = stringToWord("ANTRIAN 03");
    enqueue(&queue, tiga);
    displayQueue(queue);

    printf("\nAntrian 01 udah dilayani, dequeue = \"ANTRIAN 01\" \n");
    dequeue(&queue, &satu);
    displayQueue(queue);

    printf("\nEnqueue = \"ANTRIAN 04\" \n");
    Word empat = stringToWord("ANTRIAN 04");
    enqueue(&queue, empat);
    displayQueue(queue);

    printf("\nCek IsEmpty dan Length\n");
    if (isQueueEmpty(queue)) {
        printf("aku KOSONG\n");
    } else {
        printf("aku TIDAK KOSONG berisi %d elemen\n", queueLength(queue));
    }

    printf("\nCek IsFull\n");
    if (isQueueFull(queue)) {
        printf("aku sudah PENUH\n");
    } else {
        printf("aku masih tersedia kapasitas\n");
    }

    return 0;
}