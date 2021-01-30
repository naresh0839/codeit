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
$ crf_test -m <model file> <test file> > result.txt
```

> Here, '>' is used for storing the output after testing of data in result file.

### Now run the following commmand to get accuracy.txt file
```
$ python3 accuracy_code.py > accuracy.txt
```

### Results we got after training and testing of data are as follows:

* **Chunking**: Accuracies of 96.05082635033877, 95.64978787175211, 95.72155265213078 respectively

* **POS_tagging**: Accuracies of 94.47200118200814, 93.24988918673618, 93.47784790088018 respectively

* **NER**: Accuracies of 96.75830780565357, 96.61095816045601, 96.76412423901664 respectively.
