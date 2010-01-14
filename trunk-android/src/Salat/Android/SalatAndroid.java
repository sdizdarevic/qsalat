package Salat.Android;

import java.util.Calendar;

import android.app.Activity;
import android.os.Bundle;
import android.os.Vibrator;
import android.widget.TextView;
import android.view.Menu;
import android.view.MenuInflater;

import android.app.AlarmManager;
import android.app.PendingIntent;
import android.util.Log;
import android.content.Intent;
import android.widget.Toast;

public class SalatAndroid extends Activity {
	
	static String times[] = new String[7];
	String[] dates = new String[4];
	static Calendar cal = Calendar.getInstance();
	static int year;
	static int month;
	static int day;
	private static final String TAG = "SomeApp "; 
	protected Toast mToast; 
	static String nextSalat;
	PendingIntent sender;
	Boolean firstTime = true;
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        initCalendar();     
        setSalatTimes();
        setHijriDate();      
        printFajrTime();
        printDuhrTime();
        printAsrTime();
        printMaghribTime();
        printIshaTime();
        printShouroukTime(); 
        
        setAlarm();        
    }
    
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.options_menu, menu);
        return true;
    }
    
    public void initCalendar()
    {    	
        year = cal.get(java.util.Calendar.YEAR);
        month = cal.get(java.util.Calendar.MONTH);
        day = cal.get(java.util.Calendar.DAY_OF_MONTH); 
    }
    
    public void setSalatTimes()
    {
    	Salat prayers = new Salat();
		
		prayers.setCalcMethod(2);
		prayers.setAsrMethod(0);
		prayers.setDhuhrMinutes(0);
		prayers.setHighLatsMethod(0);
		
		times = prayers.getDatePrayerTimes(year,month+1,day,45.5454,-73.6391,-5); 
    }
    
    public void setHijriDate()
    {
    	Hijri hijri = new Hijri();		
		dates = hijri.isToString(year,month+1,day,0);
		TextView date1Text =	(TextView)  this.findViewById(R.id.date1Text);
		date1Text.setText(dates[0] + " " + dates[1] + " " + dates[3]); 
    }
    
    public void printFajrTime()
    {    	
    	TextView fajrText =	(TextView)  this.findViewById(R.id.fajrText);
        fajrText.setText(times[0]); 
    }
    
    public void printDuhrTime()
    {
    	TextView duhrText =	(TextView)  this.findViewById(R.id.duhrText);
        duhrText.setText(times[2]); 
    }
    
    public void printAsrTime()
    {
    	TextView asrText =	(TextView)  this.findViewById(R.id.asrText);
        asrText.setText(times[3]); 
    }
    
    public void printMaghribTime()
    {
    	TextView maghribText =	(TextView)  this.findViewById(R.id.maghribText);
        maghribText.setText(times[5]); 
    }
    
    public void printIshaTime()
    {
    	TextView ishaText =	(TextView)  this.findViewById(R.id.ishaText);
        ishaText.setText(times[6]); 
    }
    
    public void printShouroukTime()
    {
    	TextView shouroukText =	(TextView)  this.findViewById(R.id.shouroukText);
        shouroukText.setText(times[1]); 
    }
    
    private static long timeDiff(Calendar calendar1, Calendar calendar2)
    {
        long milliseconds1 = calendar1.getTimeInMillis();
        long milliseconds2 = calendar2.getTimeInMillis();
        long diff = milliseconds2 - milliseconds1;
        return diff;
        
    }
    
    public static long getNextSalat()
    {
    	if (getFajr() > 0) 
    	{
     		nextSalat = "Fajr";
    		return getFajr();
    	}
    	else if (getDuhr() > 0) 
    	{
    		nextSalat = "Duhr";
    		return getDuhr();
    	}
    	else if (getAsr() > 0) 
    	{
    		nextSalat = "Asr";
    		return getAsr();
    	}
    	else if (getMaghrib() > 0)
    	{
    		nextSalat = "Maghrib";
    		return getMaghrib();
    	}
    	else if (getIsha() > 0)
    	{
    		nextSalat = "Isha";
    		return getIsha();
    	}
    	else 
    	{   nextSalat = "Fajr";
    		return getMidNight();
    	}
    }
    
    private static long getFajr()
    {
    	String[] times_ = times[0].split(":");
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]));
		return timeDiff(cal,time_);
    }
    
    private static long getDuhr()
    {
    	String[] times_ = times[2].split(":");
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]));
    	return timeDiff(cal,time_);
    }
    
    private static long getAsr()
    {
    	String[] times_ = times[3].split(":");
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]));
    	return timeDiff(cal,time_);
    }
    
    private static long getMaghrib()
    {
    	String[] times_ = times[5].split(":");
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]));
    	return timeDiff(cal,time_);
    }
    
    private static long getIsha()
    {
    	String[] times_ = times[6].split(":");
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, Integer.parseInt(times_[0]), Integer.parseInt(times_[1]));
    	return timeDiff(cal,time_);
    }
    
    private static long getMidNight()
    {
    	Calendar time_ = Calendar.getInstance();
    	time_.set(year, month, day, 24, 00);
    	return timeDiff(cal,time_);
    }
    
    private void startTimer(long timeLeft)
    {
    	try {
    		//Calendar cal = Calendar.getInstance();
    		AlarmManager am = (AlarmManager) getSystemService(ALARM_SERVICE);
    		long ms = cal.getTimeInMillis();
    		//am.cancel(sender);
    		Intent intent        = new Intent(SalatAndroid.this, AReceiver.class);
    		sender = PendingIntent.getBroadcast(this, 999999999, intent, 0);    		
    		am.set(AlarmManager.RTC_WAKEUP, ms+timeLeft, sender); 
    		Toast.makeText(SalatAndroid.this, " Next Salat is  "+nextSalat , Toast.LENGTH_LONG).show();
    		((Vibrator)getSystemService(VIBRATOR_SERVICE)).vibrate(300);
    		} catch (Exception e) {
            	Log.e(TAG, "ERROR IN CODE:"+e.toString());
            }
    } 
    
    public void setAlarm()
    {
    	 startTimer(getNextSalat());
    }
    
}