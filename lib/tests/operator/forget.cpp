#include <gtest/gtest.h>
#include "../../operator/forget.h"
#include "../../operator/sto.h"
#include "../../literal/program.h"
#include "../../literal_definition/whitespace.h"
#include "../../literal_definition/numeric.h"
#include "../../literal_definition/operator_numeric.h"
#include "../../literal_definition/operator_equal_comparison.h"
#include "../../literal_definition/operator_strict_comparison.h"
#include "../../literal_definition/expression.h"
#include "../../literal_definition/program.h"

TEST(ForgetOperator,NumAndAtomGoodDeletion) {
    LiteralsStack stack;
    VariableMap variableMap;
    ProgramMap programMap;
    Lexer *lexer = new Lexer();
    lexer->addDefinition(new WhitespaceLiteralDefinition());
    lexer->addDefinition(new NumericLiteralDefinition);
    lexer->addDefinition(new OperatorNumericLiteralDefinition);
    lexer->addDefinition(new OperatorEqualComparisonLiteralDefinition);
    lexer->addDefinition(new OperatorStrictComparisonLiteralDefinition);
    lexer->addDefinition(new ExpressionLiteralDefinition);
    lexer->addDefinition(new ProgramLiteralDefinition);
    lexer->addDefinition(new AtomLiteralDefinition);
    stack.push(LiteralPointer(new NumericLiteral(4,5,4,5)));
    stack.push(LiteralPointer(new ExpressionLiteral("'AFR'")));

    EXPECT_EQ(2, stack.size());

    StoOperator stoOperator(variableMap,programMap,*lexer);
    stoOperator.apply(stack);

    EXPECT_EQ(0, stack.size());
    EXPECT_EQ(1,variableMap.size());
    EXPECT_EQ("4/5$4/5",variableMap.get("AFR")->toString());

    stack.push(LiteralPointer(new ExpressionLiteral("'AFR'")));

    EXPECT_EQ(1, stack.size());

    ForgetOperator forgetOperator(variableMap,programMap);
    forgetOperator.apply(stack);

    EXPECT_EQ(0,variableMap.size());
}

TEST(ForgetOperator,ProgramAndAtomGoodDeletion) {
    LiteralsStack stack;
    VariableMap variableMap;
    ProgramMap programMap;
    Lexer *lexer = new Lexer();
    lexer->addDefinition(new WhitespaceLiteralDefinition());
    lexer->addDefinition(new NumericLiteralDefinition);
    lexer->addDefinition(new OperatorNumericLiteralDefinition);
    lexer->addDefinition(new OperatorEqualComparisonLiteralDefinition);
    lexer->addDefinition(new OperatorStrictComparisonLiteralDefinition);
    lexer->addDefinition(new ExpressionLiteralDefinition);
    lexer->addDefinition(new ProgramLiteralDefinition);
    lexer->addDefinition(new AtomLiteralDefinition);
    stack.push(LiteralPointer(new ProgramLiteral("[1 1 +]")));
    stack.push(LiteralPointer(new ExpressionLiteral("'AFR'")));

    EXPECT_EQ(2, stack.size());

    StoOperator stoOperator(variableMap,programMap,*lexer);
    stoOperator.apply(stack);

    EXPECT_EQ(0, stack.size());
    EXPECT_EQ(1,programMap.size());
    std::unordered_map<string, LiteralVector>::const_iterator it = programMap.begin();
    string value;

    for(LiteralVector::const_iterator it2 = it->second.begin();it2!=it->second.end();++it2)
    {
        value += (*it2)->toString() + " ";
    }
    EXPECT_EQ("[1 1 +] ",value);

    stack.push(LiteralPointer(new ExpressionLiteral("'AFR'")));

    EXPECT_EQ(1, stack.size());

    ForgetOperator forgetOperator(variableMap,programMap);
    forgetOperator.apply(stack);

    EXPECT_EQ(0,programMap.size());
}

TEST(ForgetOperator,FailNotExpressionForgetAtom) {
    LiteralsStack stack;
    VariableMap variableMap;
    ProgramMap programMap;
    Lexer lexer;
    stack.push(LiteralPointer(new NumericLiteral(4,5,4,5)));
    stack.push(LiteralPointer(new ExpressionLiteral("'AFR'")));

    EXPECT_EQ(2, stack.size());

    StoOperator stoOperator(variableMap,programMap,lexer);
    stoOperator.apply(stack);

    stack.push(LiteralPointer(new NumericLiteral(3,4,5,6)));

    ForgetOperator forgetOperator(variableMap,programMap);

    EXPECT_THROW(forgetOperator.apply(stack),InvalidOperandException);
}

