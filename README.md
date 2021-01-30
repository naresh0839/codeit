### Lab Task - 2: Part-of-Speech Tagging, Chunking and Named Entity Recognition using CRF++
---

* We have modelled all of them against three templates and tested it and saved the results in respective files.
* After this from each result we have tried to calculate the accuracy using python, numpy, pandas.

> In the main folder we have three folders for NER, POS Taggging and Chunking. In each folder we have three subfolders containing the result and template files along with accuracy of data, model file and accuracy code using which we have calculated the accuracy and train and test data.

### Command to train data:
```
$ crf_learn <template file> <train file> <model file name to be given>
```

### Command to test data:
```
crf_test -m <model file> <test file> > result.txt
```

_
bash
crf_test -m <model file> <test file> > result.txt 
 
- (Here, > used for storing the result after testing of data in result file)

Then , run,
bash
python3 accuracy_code.py > accuracy.txt

- You will get your accuracy of data in accuracy.txt file.

### Results we got after training and testing of data are as follows:

* Chunking: Accuracies of 96.05074299223236, 95.78478554542384, 95.75523471800066 respectively

* POS_tagging: Accuracies of 62.51477541371159, 92.84025667004391, 92.99645390070921 respectively

* NER: Accuracies of 95.59299687845358, 94.21641429319271, 95.30216957170832 respectively.
