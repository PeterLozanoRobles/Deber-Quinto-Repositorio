rm(list =ls()) 
library(tm) 
library(SnowballC)  
library(wordcloud) 
library(ggplot2) 
library(dplyr) 
library(readr)  
library(cluster) 
library(NLP) 
library(RColorBrewer) 
etiquetas <- read_lines("Tags.txt", skip = 4, n_max = 18368-4 ) 
str(etiquetas)  
diez <- rep(1:ceiling(length(etiquetas)/10), each = 10)
diez <- diez[1:length(etiquetas)]
nov_text <- cbind(diez, etiquetas) %>% data.frame()
nov_text <- aggregate(formula = etiquetas ~ diez,
                      data = nov_text,
                      FUN = paste,
                      collapse = " ")

nov_text <- nov_text %>% select(etiquetas) %>% as.matrix
dim(nov_text)
nov_text <- gsub("[[:cntrl:]]", " ", nov_text)
nov_text <- tolower(nov_text) 
nov_text <- removeWords(nov_text, words = stopwords("spanish")) 
nov_text <- removePunctuation(nov_text) 
nov_text <- removeNumbers(nov_text) 

#Corpus
nov_corpus <- Corpus(VectorSource(nov_text))
nov_corpus

#NubedePalabras
nov_ptd <- tm_map(nov_corpus, PlainTextDocument)
wordcloud(nov_corpus, max.words = 2247, random.order = F, colors = brewer.pal(name = "Dark2", n = 12))

