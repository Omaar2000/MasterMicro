#                                                   بسم الله الرحمن الرحيم      
import Task
import unittest
import pyautogui

NoErrors = ""
ErrorOfNoRange = "Enter valid limits please, They should be numbers!"
ErrorOfInvalidEquation  = "invalid equation!"
ErrorOfWrongLimits = "invalid range, maximum value should be greater than minimum one!"

class TestTask(unittest.TestCase):

    
    def test_InvalidEquation(self):
        Task.e.delete(0,500)
        Task.minVal.delete(0,50)
        Task.minVal.insert(0,"1")
        Task.maxVal.delete(0,50)
        Task.maxVal.insert(0,"10")
        self.assertEqual(Task.button_PLOT(), ErrorOfInvalidEquation)

    def test_InvalidEquation2(self):
        Task.e.delete(0,500)
        Task.e.insert(0,"xa")
        Task.minVal.delete(0,500)
        Task.minVal.insert(0,"-10")
        Task.maxVal.delete(0,500)
        Task.maxVal.insert(0,"10")
        self.assertEqual(Task.button_PLOT(), ErrorOfInvalidEquation)

    def test_NoRange1(self):
        Task.e.delete(0,500)
        Task.e.insert(0,"X")
        Task.minVal.delete(0,500)
        Task.minVal.insert(0,"")
        Task.maxVal.delete(0,500)
        Task.maxVal.insert(0,"")
        self.assertEqual(Task.button_PLOT(), ErrorOfNoRange)

    
    def test_NoRange2(self):
        Task.e.delete(0,500)
        Task.e.insert(0,"X")
        Task.minVal.delete(0,500)
        Task.minVal.insert(0,"")
        Task.maxVal.delete(0,500)
        Task.maxVal.insert(0,"")
        self.assertEqual(Task.button_PLOT(), ErrorOfNoRange)

    def test_NoRange3(self):
        Task.e.delete(0,500)
        Task.e.insert(0,"X")
        Task.minVal.delete(0,500)
        Task.minVal.insert(0,"-10")
        Task.maxVal.delete(0,500)
        Task.maxVal.insert(0,"")
        self.assertEqual(Task.button_PLOT(), ErrorOfNoRange)

    def test_wrongLimits(self):
        Task.e.delete(0,500)
        Task.e.insert(0,"X")
        Task.minVal.delete(0,500)
        Task.minVal.insert(0,"-10")
        Task.maxVal.delete(0,500)
        Task.maxVal.insert(0,"-100")
        self.assertEqual(Task.button_PLOT(), ErrorOfWrongLimits)

    def test_wrongLimits2(self):
        Task.e.delete(0,50)
        Task.e.insert(0,"X")
        Task.minVal.delete(0,500)
        Task.minVal.insert(0,"100")
        Task.maxVal.delete(0,50)
        Task.maxVal.insert(0,"-100")
        self.assertEqual(Task.button_PLOT(), ErrorOfWrongLimits)



    def test_NoErrors2(self):
        Task.e.delete(0,500)
        Task.maxVal.delete(0,50)
        Task.minVal.delete(0,50)
        Task.e.insert(0,"2*x^2 + 6")
        Task.minVal.insert(0,"-20")
        Task.maxVal.insert(0,"20")
        self.assertTrue( Task.button_PLOT() == NoErrors)

    def test_NoErrors3(self):
        Task.e.delete(0,500)
        Task.maxVal.delete(0,50)
        Task.minVal.delete(0,50)
        Task.e.insert(0,"1/x")
        Task.minVal.insert(0,"-50")
        Task.maxVal.insert(0,"50")
        self.assertTrue( Task.button_PLOT() == NoErrors)

    def test_NoErrors4(self):
        Task.e.delete(0,500)
        Task.maxVal.delete(0,50)
        Task.minVal.delete(0,50)
        Task.e.insert(0,"5*x^3 + 2*x")
        Task.minVal.insert(0,"-50")
        Task.maxVal.insert(0,"50")
        self.assertTrue( Task.button_PLOT() == NoErrors)

    def test_NoErrors5(self):
        Task.e.delete(0,500)
        Task.maxVal.delete(0,50)
        Task.minVal.delete(0,50)
        Task.e.insert(0,"x**2")
        Task.minVal.insert(0,"-10")
        Task.maxVal.insert(0,"100")
        self.assertTrue( Task.button_PLOT() == NoErrors)

    def test_NoErrors(self):
        Task.e.delete(0,500)
        Task.maxVal.delete(0,50)
        Task.minVal.delete(0,50)
        Task.e.insert(0,"x")
        Task.minVal.insert(0,"-50")
        Task.maxVal.insert(0,"50")
        self.assertTrue( Task.button_PLOT() == NoErrors) 
    


if __name__ == '__main__' :
    unittest.main()


    #                                                    ^_^ والحمد لله رب العالمين      