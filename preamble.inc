% vim: ft=tex

% ---------------------------------------------------------------
% Determine pater size and layout based on parameter "papersize"
% Allowed values for "papersize": [4,5,6]
% ---------------------------------------------------------------
\if\papersize4
  \documentclass[12pt]{article}
  \usepackage[a4paper, twocolumn]{geometry}
  \geometry{
    total={192mm,280mm},
    includehead,
    headsep=5mm,
    top=5mm,
    left=10mm,
    footskip=5mm,
    marginparwidth=0mm,
    marginparsep=0mm,
  }
\fi
\if\papersize5
  \documentclass[10pt]{article}
  \usepackage[a5paper, twocolumn]{geometry}
  \geometry{
    total={130mm,190mm},
    includehead,
    headsep=5mm,
    top=5mm,
    left=10mm,
    footskip=5mm,
    marginparwidth=0mm,
    marginparsep=0mm,
  }
\fi
\if\papersize6
  \documentclass[10pt]{article}
  \usepackage[a6paper, twocolumn]{geometry}
  \geometry{
    total={95.5mm,130mm},
    includehead,
    headsep=2mm,
    top=5mm,
    left=5mm,
    footskip=5mm,
    marginparwidth=0mm,
    marginparsep=0mm,
    }
\fi

% ---------------------------------------------------------------
% Global Layout Settings
% ---------------------------------------------------------------
\setlength{\parindent}{0pt} %Prevents indent of the body
\usepackage{cuprum}
\usepackage[T1]{fontenc}

% ---------------------------------------------------------------
% Debugging - Activate line below to see frame outlines
% ---------------------------------------------------------------
%\usepackage{showframe} %

% ---------------------------------------------------------------
% Generic Package Imports
% ---------------------------------------------------------------
\usepackage{multirow}
\usepackage{booktabs}% def toprule, midrule and etc.
\usepackage{tikz}
\usepackage{environ}
\usepackage{xcolor,colortbl}
\usepackage{fancyhdr}
\usepackage{lastpage}

% ---------------------------------------------------------------
% Header and Footer Section
% ---------------------------------------------------------------
\pagestyle{fancy}
\renewcommand{\headrulewidth}{0pt}
\renewcommand{\footrulewidth}{0pt}

% Set Header
\renewcommand{\title}[1]{\fancyhead[C]{\textbf{\large{ #1 }}}}

% Set Footer
\cfoot{\textcolor{lightgray}{\footnotesize\thepage\ of \pageref{LastPage}}}
\newcommand{\versionchecklist}[1]{\lfoot{\textcolor{lightgray}{\footnotesize Version #1}}}
\newcommand{\datechecklist}[1]{\rfoot{\textcolor{lightgray}{\footnotesize#1}}}

% ---------------------------------------------------------------
% Checklist Environment Definitions
% ---------------------------------------------------------------

% creates empty checkboxes to be used as the second
% argument to \item on checklist
\newcommand{\checkbox}{\makebox[3ex][r]{\Large{$\square$}}}

% draws a box around a checklist group
\NewEnviron{memoryitem}{\par
\begin{tikzpicture}
\node[rectangle,minimum width=0.95\linewidth] (m)
  {\begin{minipage}{0.95\linewidth}
    \begin{center}\vspace{0.5em}\BODY\end{center}
   \end{minipage}};
\draw[solid](m.south west) rectangle (m.north east);
\end{tikzpicture}\vspace{0.75em}
}

% checklist env sets up a table and format the items.
% in case a item has steps use the \step{asdf}
% command.
\newenvironment{checklist}[2][black!90]{%
  % Base element for checklist, representing steps. 
  \renewcommand{\item}[2]{%
    ##1\dotfill\makebox{\uppercase{##2}}\\
  }
  % Indented paragraph, used for notes within a step
  \newcommand{\hint}[1]{%
    \small\hspace*{0.8em}##1\\
  }
  
  % Creates a decision header
  \newcommand{\decision}[1]{%
    \textbf{##1}\\
  }
  \newcommand\vertbar{\kern1pt\rule[-\dp\strutbox]{.8pt}{\baselineskip}\kern1pt}
  
  % Subelement for decision, representing steps
  \newcommand{\step}[1]{%
    \hspace*{0.5em}\vertbar\hspace*{\labelsep}##1\\
  }

  \begin{tabular}{p{0.9\linewidth}}
       \multicolumn{1}{c}{\cellcolor{#1}\color{white}\textbf{\uppercase{#2}}}\\
       \vspace{0.25em}
}{\end{tabular}\vspace{0.5em}}