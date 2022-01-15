#include "worker.h"

void Worker::run()
{
	int i = 0;
	while (i<100) {
		if (QRandomGenerator::global()->generate() % 10000 == 0) {
			emit valueChanged(i);
			i++;
		}
	}
}

Worker::Worker()
{

}
