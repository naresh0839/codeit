# Morphological Generation/Inflection

> A morpheme is the smallest meaningful word in a sentence or a phrase in any language. In well-spaced sentences, Morphological Analysis(MA) is the first step in Neuro-Linguistic Programming(NLP) in which a sentence is divided into a sequence of morphemes and then we determine parts of speech of the segmented morpheme. 	Morphological generation is just inverse of Morphological analysis. Morphlogical inflection Generation is the task of generating the inflected form of a given lemma corresponding to a particular lingusitic transformation. It is a mechnaism of word formation to express different grammatical categories such as tense, mood, voice, aspect, person, gender, number etc. Here, we are doing morphological generation/inflection for only single language at a time.

## Motivation:

> To do Morphological generation for languages Hindi(high resource), Bengali(low resource), german(high resource) and middle-high-german(low resource). The aim of this project is to generate inflected word forms given the lemma and a morphological feature specification. An encoder-decoder model is used, modified by a custom trainer that trains only with the target language resources after aspecific threshold.

## Tools Used:

- pytorch
- pandas
- matplotlib
- high resource Hindi and German dataset, low resource middle-high-german and bengali dataset.
- numpy
- random

## Procedure:

- `Step 1`: We use the code from this given repository.
- `Step 2`: Clone this repository into your system. (https://github.com/NLPRL/Exploratory-Projects-Spring-2019-Morph-Generation.git)
- `Step 3`: Use colab to work faster and efficiently.
- `Step 4`: Open a new notebook in colab and upload respective language datasets for training, testing and high/low resource and edit file_name variable to respective high low, test file to respective test file name.
- `Step 5`: Go to line number 616 617 618 where comment (s2s = torch.load('saved.pt')) this line and uncomment the the above two train and save statements.
- `Step 6`: Run this code , after 30 Epochs u will get two graphs for Loss and Accuracy and actual prediction data.
- `Step 7`: You will get test accuracy printed at second last line in ouput.

## Folder Structure:

- Main folder contain README.md, ipynb file and model ('saved.pt'), dataset folder that has dataset used for training testing of model and Loss_Accuracy.png which is graph image of loss accurcy of model.
- In the ipynb file, we have two graphs of loss and accurcay, actual and prediction data and test accuracy.

## Result:

- *For Hindi* with high resource: 

	- we get Avg_TrainAccuracy: 0.987051 and test accuracy as 0.9183067448762109 .

- *For Bengali* with low resource :

	- We get Avg_TrainAccuracy: 0.952591 and test accuracy as 0.9208812886459944 .

- *For German* with high resource:

	- we get Avg_TrainAccuracy: 0.950101 and test accuracy as 0.8859423938479073

- *For middle-high-german* with low resource:

	- 

> In ipynb file, we have complete graph for Loss and Accuracy and all other important results.
