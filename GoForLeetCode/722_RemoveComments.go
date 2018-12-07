package main

import "strings"
import "fmt"

func removeComments(source []string) []string {
    var code []string
    wholeLine := strings.Join(source, "\n") + "\n"
    var tempLine string
    
    for wholeLine != "" {
        ssIndex := strings.Index(wholeLine, "/*")
        slIndex := strings.Index(wholeLine, "//")
        if ssIndex == slIndex {
            tempLine += wholeLine
            break
        } else if ssIndex == -1{
            wholeLine = curStr(&tempLine, wholeLine, slIndex, "\n")
        } else if slIndex == -1{
            wholeLine = curStr(&tempLine, wholeLine, ssIndex, "*/")
        } else if ssIndex > slIndex {
            wholeLine = curStr(&tempLine, wholeLine, slIndex, "\n")
        } else if ssIndex < slIndex {
            wholeLine = curStr(&tempLine, wholeLine, ssIndex, "*/")
        }
    
    }
    for _, line := range strings.Split(tempLine, "\n") {
        if line != "" {
            code = append(code, line)
        }
    }
    return code
}

func curStr(tempLine *string, wholeLine string, index int, corres string) string{
    (*tempLine) += wholeLine[:index]
    wholeLine = wholeLine[index + 2:]
    if corres == "\n" {
        wholeLine = wholeLine[strings.Index(wholeLine, corres):]
    } else
    {
        wholeLine = wholeLine[strings.Index(wholeLine, corres) + len(corres):]
    }
    return wholeLine
}

func main() {
     code := []string {"dsf", "    //sdfsdfa", "   /*fsdfs", "sdfsdf", "fsdfsdf", "  sdfasdf   */   ", "//sdfsdf", "%fsdfsdf", "fefwe"}
    //code := []string {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"}
    // code := []string {"a//*b//*c","blank","d//*e/*/f"}
    //code := []string {"struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"}
    result := removeComments(code)
    fmt.Println(strings.Join(result, "\n"))
}

// a//*b//*c
// blank
// d//*e/*/f

// ["struct Node{", "    /*/ declare members;/**/", "    int size;", "    /**/int val;", "};"
// ]
// struct Node{
// /*/ declare members;/**/
// int size;
//     /**/int val;
// };