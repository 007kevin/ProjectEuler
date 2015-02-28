ll system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" " settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" " will be overwritten everytime an upgrade of the vim packages is performed.
" " It is recommended to make changes after sourcing debian.vim since it
" alters
" " the value of the 'compatible' option.
"
" " This line should not be removed as it ensures that various options are
" " properly set to work with the Vim-related packages available in Debian.
" runtime! debian.vim
"
" " Uncomment the next line to make Vim more Vi-compatible
" " NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes
" numerous
" " options, so any other options should be set AFTER setting 'compatible'.
" "set compatible
"
" " Vim5 and later versions support syntax highlighting. Uncommenting the next
" " line enables syntax highlighting by default.
" "if has("syntax")
" "  syntax on
" "endif
"
" " If using a dark background within the editing area and syntax highlighting
" " turn on this option as well
" "set background=dark
"
" " Uncomment the following to have Vim jump to the last position when
" " reopening a file
" "if has("autocmd")
" "  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe
" "normal! g'\"" | endif
" "endif
"
" " Uncomment the following to have Vim load indentation rules and plugins
" " according to the detected filetype.
" "if has("autocmd")
" "  filetype plugin indent on
" "endif
"
 The following are commented out as they cause vim to behave a lot
 differently from regular Vi. They are highly recommended though.
set showcmd      " Show (partial) command in status line.
set showmatch        " Show matching brackets.
set ignorecase       " Do case insensitive matching
set smartcase        " Do smart case matching
set incsearch        " Incremental search
set autowrite        " Automatically save before commands like :next and
 :make
set hidden       " Hide buffers when they are abandoned
set mouse=a      " Enable mouse usage (all modes)

 Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
"endif

"
 set nocompatible                " choose no compatibility with legacy vi
 syntax enable
 set encoding=utf-8
 set showcmd                     " display incomplete commands
 filetype plugin indent on       " load file type plugins + indentation
"
" "" Whitespace
 set nowrap                      " don't wrap lines
 set tabstop=4 shiftwidth=4      " a tab is two spaces (or set this to 4)
 set expandtab                   " use spaces, not tabs (optional)
 set backspace=indent,eol,start  " backspace through everything in insert
 mode
"
" "" Searching
 set hlsearch                    " highlight matches
 set incsearch                   " incremental searching
 set ignorecase                  " searches are case insensitive...
 set smartcase                   " ... unless they contain at least one
 capital letter
"
 set number
 set so=999
"
     nmap <S-Enter> O<Esc>
       nmap <CR> o<Esc>
"
"
"
