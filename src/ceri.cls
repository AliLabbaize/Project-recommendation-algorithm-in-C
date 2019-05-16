%% Classe de rapport pédagogique v3.7
%%
%% Vincent Labatut 2014-2017
%%
%% v1     - 10/2014 : forme de rapport très différente
%% v2     - 02/2015 : modèle complètement refait
%% v2.1   - 03/2015 : définition de la page de titre
%% v2.2   - 03/2015 : correction de quelques bugs
%% v2.3   - 04/2015 : page de titre complétée (date, adresse postale, long titre)
%% v2.4   - 12/2015 : diverses modifications du contenu du document
%% v3     - 01/2016 : définition de la classe LaTeX, correction de quelques erreurs dans le texte
%% v3.1   - 02/2016 : package icomma pour les virgules décimales en français
%% v3.2   - 04/2016 : ajout de l'option "light" (pas de page de garde, compilation plus rapide)
%% v3.3   - 05/2016 : ajout de l'option "full" (page de garde, tables des figures et tableaux)
%% v3.4   - 10/2016 : un nom d'auteur par ligne, titre possible sur deux lignes
%% v3.5   - 09/2017 : ajout du pseudo-code (package algorithm2e) et du groupe en page de titre
%% v3.6   - 10/2017 : passage de la bibliographie en BibLaTeX (au lieu de BibTeX)
%% v3.7   - 11/2017 : paragraphes désormais plus numérotés, insertion optionnelle d'un résumé
%% v3.7.1 - 11/2017 : corrections diverses dans le contenu
%% v3.7.2 - 12/2017 : précision sur les références bibliographiques
%% v3.7.3 - 12/2017 : corrections diverses dans le contenu
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% init class
	\NeedsTeXFormat{LaTeX2e}
	\ProvidesClass{ceri}[2016/01/08 Report LaTeX class]
	\LoadClass[a4paper, 11pt, final]{report}	% based on the existing latex class


% various packages
	\RequirePackage{xspace}						% used by babel
%	\RequirePackage[numbers]{natbib}			% incompatible with biblatex
	\RequirePackage[english,french]{babel}		% necessary for french documents
	\RequirePackage[utf8]{inputenc}				% use source file containing diacritics
	\RequirePackage[T1]{fontenc}				% select font encoding and allow hyphenation
	\RequirePackage[table]{xcolor}				% put colors in the document
	\let\normalcolor\relax
	\RequirePackage{lmodern}					% use specific fonts
	\RequirePackage{graphicx}					% include pictures
	\RequirePackage{url}						% display urls
	\RequirePackage{amssymb}					% extended equations
	\RequirePackage{amsmath}					% extended equations
	\RequirePackage{xifthen}					% if/then expressions
	\RequirePackage{lastpage}					% last page number
	\RequirePackage{textcomp}					% degree character
	\RequirePackage{printlen}					% display lengths
	\RequirePackage{xstring}					% handle strings functions
	\RequirePackage{subfig}						% subfloats (subfigures, subtables...)
	\RequirePackage{float}	 					% custom floats environments
%	\RequirePackage{tocloft}	 				% list of custom float objects
	\RequirePackage{setspace}
	\RequirePackage[french]{varioref}
	\RequirePackage{tikz}
		\usetikzlibrary{arrows,calc,decorations.markings,math,arrows.meta}	% necessary to draw graphs
		\tikzset{>=latex}													% same thing here
	\RequirePackage{authoraftertitle}			% access title and author names
	\RequirePackage{fancyhdr}					% custom headers and footers
	\RequirePackage{icomma}						% no space inserted after commas in expressions such as 1,23
	\RequirePackage{draftwatermark}				% watermark
	\RequirePackage[french,boxed,linesnumbered]	% pseudocode
    	{algorithm2e}
    \SetAlCapFnt{\color{TextColor}}
	\RequirePackage{tabularx} 					% for larger tables


% due to a warning
	\setlength{\headheight}{13.6pt}


% needed for UAPV title page formating
	\RequirePackage{soul}
	\RequirePackage{graphicx}
	\sodef\ugg{}{.4em plus 1fill}{1em plus 2 fill}{2em plus 2fill minus.1em}


% custom margins
	\RequirePackage[top=2.5cm, bottom=2.5cm, left=2.5cm, right=2.5cm]{geometry} 	


% thick lines in the tables
	\newcommand{\HRule}{\rule{\linewidth}{0.5mm}}


% colors
	\definecolor{DarkColor}{gray}{0.75}
	\definecolor{LightColor}{gray}{0.9}
	\definecolor{LightGrey}{rgb}{0.96,0.96,0.96}
	\definecolor{DarkGrey}{rgb}{0.83,0.83,0.83}
	\definecolor{BaseColor}{rgb}{0.64,0.69,0.31}
	\definecolor{TextColor}{rgb}{0.0, 0.45, 0.73} %TITLES !!


% setup watermark
	\SetWatermarkText{ }
	\SetWatermarkScale{1}
	\SetWatermarkLightness{0.95}


% macros allowing to set the document info
	\def\classname#1{\gdef\myclassname{#1}}
	\def\formation#1{\gdef\myformation{#1}}
	\def\groupe#1{\gdef\mygroup{#1}}
	\def\parcours#1{\gdef\myparcours{#1}}
	\def\resume#1{\gdef\myresume{#1}}
	

% hyperlinks
	\RequirePackage[
		bookmarks=true, bookmarksnumbered=true, bookmarksopen=true,
		unicode=true, colorlinks=true, linktoc=all, %linktoc=page
		linkcolor=TextColor, citecolor=TextColor, filecolor=TextColor, urlcolor=TextColor,
		pdfstartview=FitH
]{hyperref}


% arrays and tables
	\RequirePackage{array}							% handle arrays
	% Macro by A. Kassi 
	% http://www.ukonline.be/programmation/latex/tutoriel/chapitre4/page2.php
	\makeatletter
		\def\hlinewd#1{
		\noalign{\ifnum0=`}\fi\hrule \@height #1
		\futurelet\reserved@a\@xhline}
	\makeatother
	% end macro


% NOTE: only (?) for the report class
	\RequirePackage{chngcntr}
	\counterwithout{section}{chapter}		% hide the chapter number in section headings


% change default font
	\renewcommand{\familydefault}{\sfdefault}


% custom list bullets
%	\renewcommand{\labelitemi}{$\bullet$}
	\renewcommand{\FrenchLabelItem}{\textbullet}


% custom captions
	\RequirePackage{caption}
	\captionsetup{
		labelfont={color=TextColor, bf, small},	% font(sf), color, bold, size of the caption label
		textfont={small},						% font(sf) and size of the caption text itself
		labelsep=period,						% separator between label and text
		margin=10mm								% left/right margins
	}


% custom equations
	\makeatletter								% change equation numbers
	\def\tagform@#1{\maketag@@@{(\color{TextColor}\textbf{#1}\normalcolor)\@@italiccorr}}
	\makeatother


% custom section headers
	\makeatletter
		\renewcommand{\section}{
		    \@startsection{section}{1}{0pt}
		    {-3.5ex plus -1ex minus -.2ex}
		    {2.3ex plus.2ex}
		    {\color{TextColor}\normalfont\Huge\bfseries}
		}
		\renewcommand\subsection{
		    \@startsection{subsection}{2}{\z@}
	    		{-3.25ex\@plus -1ex \@minus -.2ex}
		    {1.5ex \@plus .2ex}
		    {\color{TextColor}\normalfont\large\bfseries}
		}
		\renewcommand\subsubsection{
	    		\@startsection{subsubsection}{3}{\z@}
	    		{-3.25ex\@plus -1ex \@minus -.2ex}
	    		{1.5ex \@plus .2ex}
	    		{\color{TextColor}\normalfont\normalsize\bfseries}
		}
% 		\renewcommand\paragraph{
% 	    		\@startsection{paragraph}{4}{\z@}
% 	    		{-3.25ex\@plus -1ex \@minus -.2ex}
% 	    		{-1em}
% 	    		{\color{TextColor}\normalfont\normalsize}
% 		}
% 		\renewcommand\subparagraph{
% 	    		\@startsection{subparagraph}{5}{\z@}
% 	    		{-3.25ex\@plus -1ex \@minus -.2ex}
% 	    		{-1em}
% 	    		{\color{TextColor}\normalfont\normalsize}
% 		}
	\makeatother
%	\setcounter{secnumdepth}{5}			% number subsubsections
%	\setcounter{tocdepth}{5}			% and include them in the TOC
	\setcounter{secnumdepth}{3}			% number subsubsections
	\setcounter{tocdepth}{3}			% and include them in the TOC


% custom table of contents
	\newcommand{\tocName}{Sommaire}									% define TOC header
	\addto\captionsfrench{\renewcommand{\contentsname}{\tocName}}	% change TOC header
	
    
% custom list of figures
	\newcommand{\lofName}{Liste des figures}						% define LOF header
%	\renewcommand{\listfigurename}{\lofName}						% change LOF header (1)
	\addto\captionsfrench{\renewcommand{\listfigurename}{\lofName}}	% change LOF header (2)
	
	
% custom list of tables
	\newcommand{\lotName}{Liste des tables}							% define LOT header
%	\renewcommand{\listtablename}{\lotName}							% change LOT header (1)
	\addto\captionsfrench{\renewcommand{\listtablename}{\lotName}}	% change LOT header (2)


    
% custom date format
	\RequirePackage{datetime}


% table of contents / lists of figures & tables
	\newcommand{\MyToc}{
		\phantomsection
		%\addcontentsline{toc}{section}{\tocName}	% add the TOC in the TOC (yes! for PDF bookmarks)   non 
		\tableofcontents							% insert TOC
		\thispagestyle{fancy}						% force header/footer
		\newpage
	}
	\newcommand{\MyLof}{
		\phantomsection
		\addcontentsline{toc}{section}{\lofName}	% add the LOF in the TOC
		\listoffigures								% insert LOF
		\thispagestyle{fancy}						% force header/footer
		\newpage
	}
	\newcommand{\MyLot}{
		\phantomsection
		\addcontentsline{toc}{section}{\lotName}	% add the LOT in the TOC
		\listoftables								% insert LOT
		\thispagestyle{fancy}						% force header/footer
		\newpage
	}		


% title page
	\newcommand{\maketitleZ}{
		% setup PDF doc info
		\hypersetup{
	    	pdftitle={\ifdefined\MyTitle \MyTitle \else \fi},
		   	pdfauthor={\ifdefined\MyAuthor \MyAuthor \else \fi},
	    	pdfsubject={\ifdefined\myclassname \myclassname \else \fi}
		}
		
\begin{center}
    % title
	\Huge{\textbf{\textcolor{TextColor}{\MyTitle}}} \\[2cm]
    % authors
	\Large{\MyAuthor} \\[2cm]

    
    % date
	\Large{\today} 
	
\end{center}

	}
	\renewcommand{\maketitle}{\maketitleZ}
    
% "light" option
	\DeclareOption{light}{%
		%\SetWatermarkText{BROUILLON}

		\renewcommand{\maketitle}{
			% setup PDF doc info
			\hypersetup{
	    		pdftitle={\ifdefined\MyTitle \MyTitle \else \fi},
		    	pdfauthor={\ifdefined\MyAuthor \MyAuthor \else \fi},
	    		pdfsubject={\ifdefined\myclassname \myclassname \else \fi}
			}
			
			% custom headers and footers
			\pagestyle{fancy}
			\fancyhf{}
			\renewcommand{\headrulewidth}{0.4pt}
			\renewcommand{\footrulewidth}{0.4pt}
			\cfoot{\thepage\ / \pageref*{LastPage}} 
			\chead{\MyTitle} 

			% first page style
			\fancypagestyle{firststyle}
			{	\fancyhf{}
				\renewcommand{\headrulewidth}{0pt}
				\renewcommand{\footrulewidth}{0.4pt}
				\cfoot{\thepage\ / \pageref*{LastPage}} 
			}
			
			% CE DONT ON SE SERT :
			
			% draw title page
			\phantomsection 
			%\addcontentsline{toc}{section}{Titre}	% add the title page in the TOC (yes! for PDF bookmark), c'est non.
			\begin{center} \\[1.5cm]
            	% title
            	
				\HRule \\[0.4cm]
				\fontsize{50}{60}{\textbf{\textcolor{TextColor}{\MyTitle}}} 
				\HRule \\[0.5cm] 
				
                % authors
				\Large{
				Présenté par : \\
				\MyAuthor \\[0.7cm] 
				 
				 \includegraphics[width=0.7\textwidth]{images/Dasilflix.jpg} \\[0.7cm] 
				 
				 % encadrants
				 Encadrants : \\
				    Jonathan ARNAULT \\
                    Gérald OSTER \\
                    Pierre MONNIN \\
                    Olivier FESTOR \\
                    Soline BLANC \\
                    Sabeur ARIDHI \\
                    Sébastien DA SILVA \\[1cm]
                % date
                
				5 mars 2018 - 1 Juin 2018}\\[0.5cm]
				\HRule\\[0.4cm]
				% abstract
	        	\ifdefined\myresume
					\phantomsection
					\addcontentsline{toc}{section}{\abstractname}	% add the abstract in the TOC
					\parbox[c][][s]{0.75\textwidth}{\footnotesize \vspace{0.5cm} \noindent \textbf{\abstractname.} \myresume}
				\else\fi
			\end{center}	
	
			\setcounter{page}{1} 		% set the second page... to number 2
			\thispagestyle{firststyle}	% force header/footer
		}
	}
% "full" option
	\DeclareOption{full}{%
		\renewcommand{\maketitle}
        {	\maketitleZ
	    	% Insert list of figures
			\MyLof
			% Insert list of tables
			\MyLot
		}
    }
	\ProcessOptions